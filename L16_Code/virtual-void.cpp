#include <iostream>
using namespace std;
class base {
  public:
     virtual void vfunc() {
      cout << "This is base's vfunc().\n";
      }
};
 class child : public base {
   public:
      void vfunc() {
        cout << "This is child's vfunc().\n";
    }
};

int main()
{
  base *p_b, b;
  base *p_a[4];
  child c1;
  // point to base
  p = &b;
  p->vfunc(); // access base's vfunc()
  // point to child
  p = &c1;
  p->vfunc(); // access child's vfunc()

  p_a[0] = new base();
  p_a[1] = &b;
  p_a[2] = new child();    
  p_a[3] = &c1;
  
  for (int i =0 ;i <4 ;i++) 
  p[i]->vFunc(); 
	 
  return 0;
}



