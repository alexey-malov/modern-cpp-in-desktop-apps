#pragma once

template <typename Signature>
using Signal = boost::signals2::signal<Signature>;
using Connection = boost::signals2::connection;
using ScopedConnection = boost::signals2::scoped_connection;

template <typename T>
class SignallingValue final
{
public:
	using Signal2 = Signal<void(const T& oldValue, const T& newValue)>;
	using Slot2 = typename Signal2::slot_type;
	using Slot1 = typename Signal<void(const T& newValue)>::slot_type;
	using Slot0 = typename Signal<void()>::slot_type;

	SignallingValue() = default;
	template <typename T>
	explicit SignallingValue(T&& value)
		: m_value(std::forward<T>(value))
	{
	}

	// No copy/assignment
	SignallingValue(const SignallingValue&) = delete;
	SignallingValue& operator=(const SignallingValue&) = delete;

	void FireChangeSignal()
	{
		m_changeSignal(m_value, m_value);
	}

	const T& GetValue() const
	{
		return m_value;
	}

	void SetValue(T value)
	{
		if (value != m_value)
		{
			using std::swap;
			swap(value, m_value);
			m_changeSignal(value, m_value);
		}
	}

	const T& operator*() const
	{
		return m_value;
	}

	void operator=(const T& newValue)
	{
		SetValue(newValue);
	}

	operator const T&() const
	{
		return m_value;
	}

	const T* operator->() const
	{
		return &m_value;
	}

	Connection Connect(const Slot2& slot)
	{
		return m_changeSignal.connect(slot);
	}

	Connection Connect(const Slot1& slot)
	{
		return Connect(Slot2([=](const T& /*oldValue*/, const T& newValue) {
			slot(newValue);
		}));
	}

	Connection Connect(const Slot0& slot)
	{
		return Connect(Slot2([=](const T& /*oldValue*/, const T& /*newValue*/) {
			slot();
		}));
	}

private:
	T m_value = {};
	Signal2 m_changeSignal;
};

struct ScopedConnections
{
	ScopedConnections() = default;

	ScopedConnections(std::initializer_list<Connection> const& connections)
	{
		*this += connections;
	}

	ScopedConnections& operator+=(const Connection& conn)
	{
		m_items.emplace_back(conn);
		return *this;
	}

	ScopedConnections& operator+=(Connection&& conn)
	{
		m_items.emplace_back(std::move(conn));
		return *this;
	}

	ScopedConnections& operator+=(ScopedConnection&& conn)
	{
		m_items.emplace_back(std::move(conn));
		return *this;
	}

	ScopedConnections& operator+=(std::initializer_list<Connection> const& connections)
	{
		for (const auto& con : connections)
		{
			*this += con;
		}
		return *this;
	}

	void DisconnectAll()
	{
		m_items.clear();
	}

private:
	std::vector<ScopedConnection> m_items;
};
