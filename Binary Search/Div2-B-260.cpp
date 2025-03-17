 //created by MoniirMo

#include <bits/stdc++.h>
using namespace std ;

int main() {
	int n ;
	double l ;
	cin >> n >> l;
	vector<double>input ;
	for(int i = 0 ; i < n ; i++) {
		double holder ;
		cin >> holder ;
		input.push_back(holder);
	}

	sort(input.begin() , input.end());
	double highest = 0 ;
	for(int i = 0 ; i < n ; i++) {
		if(i > 0 ) {
			double calc = input[i] - input[i-1] ;
			calc /= 2.0 ;
			//cout << calc << endl;
			if(calc > highest) highest = calc ;
		}
	}
	double first = input[0] - 0 ;
	double second = l - input[n-1] ;
	double holder = max(first , second) ;


	cout << fixed << setprecision(10) << max(highest , holder) << endl;

	//print the minimum light radius to light the whole street
	//the maximum length of street 1e9 which means we can have a light radius of half of the length of the street
	//we can have intensity from 1 to 5e8 (500,000,000)
}