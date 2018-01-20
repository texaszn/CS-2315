// Zach Nadeau
// CS 2315
// Lab 28


template<typename T>
vector<Frequency<T> > distribution(const vector<T>& v)
{
	vector<Frequency<T> > dist; // create a local object
	typename vector<Frequency<T> >::iterator findItr;
	typename vector<T>::const_iterator vItr;
	
	for (vItr = v.cbegin(); vItr < v.cend(); ++vItr)
	{
		findItr = find(dist.begin(), dist.end(), *vItr);
		if (findItr != dist.end())
			// then we found *vItr within dist, so increment frequency
			findItr -> increment();
		else
			// not found, so add a new Frequency at the end of dist
			dist.emplace_back(Frequency<T>(*vItr));
	}
	
	return dist; // return the local object
}

template<typename T>
ostream& operator<<(ostream& out, const vector<Frequency<T> >& v)
{
	typename vector<Frequency<T> >::const_iterator i,
		begin = v.begin(),
		end = v.end();
	
	for (i = begin; i < end; i++)
		out << i->getValue() << " -> " << i->getFrequency() << '\n';
	
	return out;
}

template<typename T>
bool Frequency<T>::operator==(const T rhs) const                   // uses find
{
	return (this->getValue() == rhs);
}

template<typename T>
bool Frequency<T>::operator< (const Frequency<T> rhs) const        // uses sort
{
	return (this->getFrequency() < rhs.getFrequency());
}
