//  Study of different operation on Set.

#include <iostream> 
#include <set> 
#include <string> 
using namespace std; 
void printSet(const set<string>& s) { 
for (const auto& name : s) { 
        cout << name << " "; 
    } 
    cout << endl; 
} 
 
int main() { 
    // Attendees who speak Spanish 
    set<string> spanishSpeakers = {"Alice", "Bob", "Carlos", "Daniel"}; 
     
    // Attendees who speak German 
    set<string> germanSpeakers = {"Eve", "Bob", "Friedrich", "Alice"}; 
 
    // Union of both sets (Speakers who speak either Spanish or German or both) 
    set<string> unionSet = spanishSpeakers; 
    unionSet.insert(germanSpeakers.begin(), germanSpeakers.end()); 
 
    // Intersection of both sets (Speakers who speak both Spanish and German) 
    set<string> intersectionSet; 
    for (const auto& name : spanishSpeakers) { 
        if (germanSpeakers.count(name)) { 
            intersectionSet.insert(name); 
        } 
    } 
 
    // Difference (Speakers who speak only Spanish) 
    set<string> differenceSet; 
    for (const auto& name : spanishSpeakers) { 
        if (!germanSpeakers.count(name)) { 
            differenceSet.insert(name); 
        } 
    } 
 
    // Displaying results 
    cout << "Union (Spanish OR German speakers): "; 
    printSet(unionSet); 
 
    cout << "Intersection (Spanish AND German speakers): "; 
    printSet(intersectionSet); 
 
    cout << "Difference (Only Spanish speakers): "; 
    printSet(differenceSet); 
 
    return 0; 
}