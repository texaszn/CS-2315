// Zach Nadeau
// CS 2315
// Lab 33


template <typename T>
void shellSort(vector<T>& v) {
	vector<T> vSub;
	typename vector<T>::iterator itrA, begin = v.begin(), end = v.end();
	int x, i = 0, k, n = v.size();
	
	for (k = 1; k <= n / 9; k = 3 * k + 1); // null statement
	
	while (k > 0) {
		while (i < k) {
			vSub.clear();
			
			for (itrA = begin + i; itrA < end; itrA += k) {
				vSub.emplace_back(*itrA);
			}
			
			insertionSort(vSub);
			
			for (itrA = begin + i, x=0; itrA < end; itrA += k, x++) {
				*itrA = vSub.at(x);
			}
			
			i++;
		}
		k /= 3;
		i = 0;
	}
}
