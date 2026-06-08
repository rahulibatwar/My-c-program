#include <iostream>
using namespace std;

class Voter {
public:
    int age;

    // 🎯 CONSTRUCTOR: Jaise hi object banega, yeh khud chal jayega!
    Voter() {
        cout << "[System Notification]: Ek naya Voter Object memory mein create ho gaya hai!" << endl;
        age = 18; // Humne default age 18 set kar di
    }

    bool checkEligibility() {
        if (age >= 18) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    cout << "--- Constructor Demo Shuru ---" << endl << endl;

    // Jaise hi yeh line chalegi, constructor automatic fire hoga!
    Voter person1; 
    
    cout << "Default age jo constructor ne set ki: " << person1.age << endl << endl;

    // Ab user se nayi age maangte hain
    cout << "Apni nayi umar (Age) enter kijiye: ";
    cin >> person1.age;

    if (person1.checkEligibility()) {
        cout << "✅ Aap vote de sakte hain!" << endl;
    } else {
        cout << "❌ Maaf kijiye, aap abhi vote nahi de sakte." << endl;
    }

    return 0;
}