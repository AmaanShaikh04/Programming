/*
case 1:
input = 1 2 3 4, output = -5 + i10

case 2:
input = 1 2 1 2, output = -3 + i4
*/
#include <iostream>
using namespace std;

struct complex {
    int re;
    int im;
};

/*struct complex wrapper(struct complex& c1, struct complex& c2){
	struct complex c;
	c.re = c1.re*c2.re - c1.im*c2.im;
	c.im = c1.re*c2.im - c1.im*c2.re;
	return c;
}*/

struct complex wrapper(struct complex c1, struct complex c2){
	struct complex c;
	int p1 = c1.re*c2.re;
	int p2 = c1.im*c2.im;
	int p3 = (c1.re + c1.im) * (c2.re + c2.im);
	c.re = p1-p2;
	c.im = p3 - (p1 + p2);
	return c;
}

int main(){
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	struct complex x1 = {a,b}, x2 = {c,d};
	struct complex x = wrapper(x1,x2);
	cout << x.re << " + i" << x.im;
	return 0;
}
