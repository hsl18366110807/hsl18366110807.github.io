#include <iostream>
#include <condition_variable>
#include <thread> 
using namespace std;
    std::mutex mutex_;
    std::condition_variable cond_;
    bool one_ok_=false;
    bool two_ok_=false;
    void first() {
        
        // printFirst() outputs "first". Do not change or remove this line.
        cout<<"_A";
        std::lock_guard<std::mutex> lock(mutex_);
        one_ok_=true;
        cond_.notify_all();
    }

    void second() {
        
        std::unique_lock<std::mutex> lock(mutex_);
    cond_.wait(lock, [&](){
        return one_ok_;
    });
    // printSecond() outputs "second". Do not change or remove this line.
  cout<<"_B";
    two_ok_ = true;
    cond_.notify_all();
    }

    void third() {
      std::unique_lock<std::mutex> lock(mutex_);
    cond_.wait(lock, [&](){
        return two_ok_;
    });
    // printThird() outputs "third". Do not change or remove this line.
   cout<<"_C";
    }
 
int main()
{   
    string s;
    cin>>s;
    cout<<s;
	thread t1(first);
	thread t2(second);
	thread t3(third);
	t1.join();
	t2.join();
	t3.join();
}
