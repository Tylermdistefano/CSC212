//Chatgpt input and returned code link
//https://urldefense.proofpoint.com/v2/url?u=https-3A__chat.openai.com_share_59a9855d-2Db1b2-2D49b1-2Db109-2D1c54a42024a9&d=DwMBaQ&c=dWz0sRZOjEnYSN4E4J0dug&r=9TfIxjW1WqMh5eiJOYFX5RmmNpJlVnh9-JFzms5wDD8&m=4kY0HKgdfRxEolOmBRl5pbPP6V9WLY22y4iMHKBIA42WDdJuZF9p7y-aVU22Lwed&s=waJ1zObHv0ikfYT8mo7Lg0Efzss5-j6hzk3DZWJ2ozg&e=

#include "DynamicArray.h"
#include <cstring>

// "Fancy" way to write a default constructor.
// Note: The other constructors can *NOT* be written this way!
DynamicArray::DynamicArray()
    : m_length(0), m_capacity(1), m_scaling_factor(2.0), m_data(new int[1]) {
}

DynamicArray::DynamicArray(double scaling_factor, unsigned int capacity) {
    m_scaling_factor = scaling_factor;
    m_capacity = capacity;
    m_data = new int[m_capacity];
}


DynamicArray::DynamicArray(double scaling_factor, unsigned int length, int default_value) {
    m_scaling_factor = scaling_factor;
    m_capacity = length; // Set capacity to the specified length
    m_data = new int[m_capacity];
    // Initialize all elements in m_data to default_value
    for (unsigned int i = 0; i < m_capacity; ++i) {
        m_data[i] = default_value;
    }
}

DynamicArray::DynamicArray(const DynamicArray& other) {
    // use the assignment operator
    (*this) = other; 
}

// Destructor: destroys the dynamically allocated array on the heap
DynamicArray::~DynamicArray() {
    delete[] m_data;
}

unsigned int DynamicArray::get_length() {
    return m_length;
}

unsigned int DynamicArray::get_capacity() {
    return m_capacity;
}

double DynamicArray::get_scaling_factor() {
    return m_scaling_factor;
}

void DynamicArray::set_scaling_factor(double value) {
    m_scaling_factor = value;
}

std::string DynamicArray::to_string() {
	// Initialize an empty string
    std::string str;
     for (unsigned int i = 0; i < m_length; ++i) {
        str += std::to_string(m_data[i]);
        if (i < m_length - 1) {
            str += " ";
        }
    }
    return str;
}

bool DynamicArray::find_first_of(int value, unsigned int *index) {
    for (unsigned int i = 0; i < m_length; ++i) {
        if (m_data[i] == value) {
            *index = i;
            return true;
        }
    }
    return false;
}

bool DynamicArray::find_last_of(int value, unsigned int *index) {
    for (int i = m_length - 1; i >= 0; --i) {
        if (m_data[i] == value) {
            *index = i;
            return true;
        }
    }
    return false;
}

void DynamicArray::append(int value) {
    if (m_length == m_capacity) {
        // Resize the array (e.g., double the capacity)
        unsigned int new_capacity = static_cast<unsigned int>(m_capacity * m_scaling_factor);
        int* new_data = new int[new_capacity];
        std::memcpy(new_data, m_data, sizeof(int) * m_length);
        delete[] m_data;
        m_data = new_data;
        m_capacity = new_capacity;
    }
    // Append the value to the end
    m_data[m_length++] = value;
}

void DynamicArray::prepend(int value) {
    if (m_length == m_capacity) {
        // Resize the array (e.g., double the capacity)
        unsigned int new_capacity = static_cast<unsigned int>(m_capacity * m_scaling_factor);
        int* new_data = new int[new_capacity];
        std::memcpy(new_data, m_data, sizeof(int) * m_length);
        delete[] m_data;
        m_data = new_data;
        m_capacity = new_capacity;
    }
    // Shift existing elements to make room for the new value
    for (int i = m_length; i > 0; --i) {
        m_data[i] = m_data[i - 1];
    }
    // Add the new value at the beginning
    m_data[0] = value;
    ++m_length;
}

void DynamicArray::remove_last() {
    if (m_length > 0) {
        --m_length;
    }
}

void DynamicArray::remove_first() {
    if (m_length > 0) {
        // Shift elements to remove the first value
        for (unsigned int i = 1; i < m_length; ++i) {
            m_data[i - 1] = m_data[i];
        }
        --m_length;
    }
}

void DynamicArray::clear() {
    delete[] m_data;
    m_data = nullptr;
    m_length = 0;
    m_capacity = 0;
}

// Examples of "operator overloading"
int& DynamicArray::operator[](unsigned int index) {
    return m_data[index];
}

DynamicArray& DynamicArray::operator=(const DynamicArray &other) {
    m_length = other.m_length;
    m_capacity = other.m_capacity;
    m_scaling_factor = other.m_scaling_factor;
    m_data = new int[m_capacity];
    std::memcpy(m_data, other.m_data, sizeof(int) * m_length);
    // this allows statements such as (a = b = c) assuming a, b, and c are all the DynamicArray type
    return (*this); 
}