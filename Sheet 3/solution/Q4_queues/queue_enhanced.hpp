#ifndef __queue_enhanced__
#define __queue_enhanced__

#include <cassert>
#include <vector>

#include "queue.hpp"

template <typename T>
class Dequeue : public Queue<T>
{
public:
    // Inherit the constructors of Queue<T>
    using Queue<T>::Queue;

    // Access the element at the back of the queue
    T& back()
    {
        assert(this->_size > 0);
        return this->_storage[_tail()];
    }

    // Const-access the element at the back of the queue
    const T& back() const
    {
        assert(this->_size > 0);
        return this->_storage[_tail()];
    }

    // Copy an element at the back of the queue
    void enqueue_front(const T& value) { _enqueue_front(value); }

    // Move an element at the back of the queue
    void enqueue_front(T&& value) { _enqueue_front(std::move(value)); }

    // Remove the element at the back of the queue
    void dequeue_front()
    {
        assert(this->_size >= 1);
        this->_size--;
        this->_position = _tail();
    }

    // Remove all elements from the queue
    void clear() { this->_size = 0; }

private:
    // Enqueue by copying or moving
    template <typename Q>
    void _enqueue_front(Q&& x)
    {
        assert(this->_size < this->_storage.size());
        this->_size++;
        this->_storage[this->_head()] = std::forward<Q>(x);
    }

protected:
    // Return the index of the element to the front of the queue
    size_t _tail() const
    {
        assert(this->_size >= 0);
        if (this->_position + 1 == this->_storage.size()) {
            return 0;
        }
        return this->_position + 1;
    }
};

#endif  // __queue_enhanced__