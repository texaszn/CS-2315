// Zach Nadeau
// CS 2315
// Lab 25


template<typename T>
Accumulator<T>::Accumulator(const T& value /* = T() */)    //constructor
{
	total = value;
}

// access and update functions
template<typename T>
T Accumulator<T>::getTotal() const                         // return total
{
	return total;
}

template<typename T>
void Accumulator<T>::addValue(const T& value)              // add (+) value to total
{
	total = total + value;
}

template<typename U>
ostream& operator<<(ostream& output, const Accumulator<U>& obj)
{
	output << Accumulator<U>::total;
	return output;
}