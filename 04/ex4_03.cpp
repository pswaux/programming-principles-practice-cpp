/**
 * Exercise 4_3
 *
 * Read a sequence of double values into a vector. Think of each value as the 
 * distance between two cities along a given route. Compute and print the total 
 * distance (the sum of all distances). Find and print the smallest and greatest 
 * distance between two neighboring cities. Find and print the mean distance 
 * between two neighboring cities.
 *
 */
#include "std_lib_facilities.h"

int main() 
{
   vector<double> distances;
   double total_distance = 0.0;

   cout << "Enter distances (type q for quit): ";
   for (double distance; cin >> distance; ) {
      total_distance += distance;
      distances.push_back(distance);
   }

   cout << "Total distance is: " << total_distance << "\n";

   sort(distances);
   cout << "The smallest distance is: " << distances[0] << "\n";
   cout << "The greatest distance is: " << distances[distances.size() - 1]
        << "\n";

   cout << "The mean distance is: " << total_distance / distances.size() << "\n";
}
