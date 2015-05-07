#include <iostream>
#include "heap.hh"

// void test_get_first_value_exceptions(Heap<int, 32> &h) {
//     // Test get_first_value() exception handler
//     try {
//         // Do something invalid, that should throw an exception.
//         h.get_first_value();

//         // If we get here then the operation didn't throw an exception!
//         std::cout << "Nothing was thrown!" << std::endl;
//     }
//     catch (std::underflow_error &e) {
//         std::cout << e.what() << std::endl;
//     }
//     catch (...) {
//         // If the function throws something other than what we expected,
//         // this catch-block will run.

//         std::cout << " Wrong thing was thrown!" << std::endl;
//     }
// }

// void test_add_value_exceptions(Heap<int, 32> &h) {

//     // Test add_value() exception handler
//     try {
//         // Do something invalid, that should throw an exception.
//         h.add_value(9999);

//         // If we get here then the operation didn't throw an exception!
//         std::cout << "Nothing was thrown!" << std::endl;
//     }
//     catch (std::overflow_error &e) {
//         std::cout << e.what() << std::endl;
//     }
//     catch (...) {
//         // If the function throws something other than what we expected,
//         // this catch-block will run.

//         std::cout << " Wrong thing was thrown!" << std::endl;
//     }
// }


/* Test the heap. */
int main(int argc, char **argv) {
  int size = 32;
  Heap<int, 32> h;

  int i;
  int lastval;

  // test_get_first_value_exceptions(h);

  try {
      h.get_first_value();
      std::cout << "Nothing was thrown!" << std::endl;
  } catch (std::underflow_error &e) {
      std::cout << e.what() << std::endl;
  } catch (...) {
      std::cout << "Wrong thing was thrown!" << std::endl;
  }

  /* Use a seed so that the sequence of random values
   * is always the same.
   */
  srand(11);


  /* Fill up the heap with random values. */
  for (i = 0; i < size; i++)
    h.add_value(rand() % 1000);


  /* Print out the results.  If anything is out of order,
   * flag it.  (Pull the very first value separately so that
   * we don't have to set lastval to something strange just
   * to get the test to work...)
   */


  lastval = h.get_first_value();
  std::cout << "Value 0 = " << lastval << std::endl;

  for (i = 1; i < size; i++) {
    int val = h.get_first_value();

    std::cout << "Value " << i << " = " << val << std::endl;
    if (val < lastval)
      std::cout << "  ERROR:  OUT OF ORDER." << std::endl;

    lastval = val;
  }

  for (i = 1; i < 51; i++) {
    // test_add_value_exceptions(h);

    std::cout << "Attempt: " << i << "  ";
    try {
        h.add_value(9999);
        std::cout << "Nothing was thrown!" << std::endl;
    }
    catch (std::overflow_error &e) {
        std::cout << e.what() << std::endl;
    }
    catch (...) {
        std::cout << " Wrong thing was thrown!" << std::endl;
    }
  }

  return 0;
}
