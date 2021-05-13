#include <iostream>
#include <map>
#include <initializer_list>
#include <set>

using namespace std;

// in 12.4, didn't we use bitmaps for state info?

template <typename E>
class State_control_base
{
public:
    typedef std::pair<E, E> transition_type;

    State_control_base() = default;
    // Nope, you want the transitions to be static
    //State_control_base(std::initializer_list<transition_type> t) { }

    void show_t()
    {
        for (const auto& i : test_)
        {
            cout << i << endl;
        }
        cout << endl;
    }

private:
    static std::set<E> test_;
    //static std::multimap<transition_type> transitions_;
};

// I think this should always be specialized by 
//template <typename E, typename S> std::set<E> State_control_base<E, S>::test_;

template <class T> class K
{
public:
      static T x;
};
template <class T> T K<T> ::x;
//State_control_base::transition_type;

//std::multimap<State_control_base::transition_type> transitions_;

enum Ch_obj_id
{
    Traffic,
    Ase,
    Ch_obj_id_max
};

enum Ch_state_id
{
    Inactive,
    Wfp,
    Adding,
    Ch_state_id_max
};

template <> 
std::set<int> State_control_base<int>::test_ = {7,1,55,87};

template <typename Ch_state_id> 
std::set<Ch_state_id> State_control_base<Ch_state_id>::test_ = {Wfp, Adding};

//template <typename E, typename S> 
//std::set<E> State_control_base<E, S>::test_ = {Ase, Traffic};

int main()
{
    // 3. 
    State_control_base<Ch_state_id> ch_state3;
    ch_state3.show_t();

//    State_control_base<Ch_obj_id> ch_state4;
//    ch_state4.show_t();

    // 1. show that static transitions work as expected - first simple test of set
    State_control_base<int> ch_state;
    ch_state.show_t();

    State_control_base<int> ch_state2;
    ch_state2.show_t();

    // typedef? works but isn't this irrelevant now that t's are static?
    State_control_base<int>::transition_type t1{1,4};

    return 0;

    std::multimap<int, int> mmi{{5,10}, {8,4}, {5,20}};

    for (const auto& i : mmi)
    {
        //cout << i.first << " : " << i.second << endl;
    }

    return 0;
}