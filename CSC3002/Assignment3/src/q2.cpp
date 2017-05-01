/*
 * File: TestQueue.cpp
 * -------------------
 * This program tests the Queue package by creating a test
 * program that implements the following commands:
 *
 *     enqueue str -- Enqueues the string onto the queue
 *     dequeue     -- Dequeues the queue and displays the value
 *     peek        -- Peeks at the first element
 *     size        -- Prints the size of the queue
 *     isEmpty     -- Prints whether the queue is empty
 *     clear       -- Clears the queue
 *     list        -- List the elements of the queue
 *     help        -- List these commands
 *     quit        -- Quits the program
 */
#include <string>

#include "simpio.h"
#include "q2.h"


using namespace std;
namespace q2 {



/* Main program */

int q2() {
   Queue<string> queue;
   TokenScanner scanner;
   scanner.ignoreWhitespace();
   scanner.scanNumbers();
   scanner.scanStrings();
   while (true) {
      scanner.setInput(getLine("> "));
//      std::cout << std::endl << "A" << queue.size() << std::endl;
      executeCommand(scanner, queue);
   }
   return 0;
}

void executeCommand(TokenScanner & scanner, Queue<string> & queue) {
   string cmd = scanner.nextToken();
   string temp;
   if (cmd == "enqueue") {
      double priority;
      priority = getDouble("priority? ", "place input a double");
      queue.enqueue(scanner.getStringValue(scanner.nextToken()), priority);
//      std::cout << scanner.getStringValue(scanner.nextToken()) << std::endl;
   } else if (cmd == "dequeue") {
      if (queue.isEmpty()) {
         cout << "Queue is empty" << endl;
      } else {
         cout << queue.dequeue() << endl;
      }
   } else if (cmd == "peek") {
      if (queue.isEmpty()) {
         cout << "Queue is empty" << endl;
      } else {
         cout << queue.peek() << endl;
      }
   } else if (cmd == "size") {
      cout << queue.size() << endl;
   } else if (cmd == "isEmpty") {
      cout << ((queue.isEmpty()) ? "true" : "false") << endl;
   } else if (cmd == "clear") {
      queue.clear();
   } else if (cmd == "list") {
      listQueue(queue);
   } else if (cmd == "help") {
      helpCommand();
   } else if (cmd == "quit") {
//      exit(0);
        throw 1;
       //       return 0;
   } else if (cmd != "") {
      cout << "Unrecognized command: " << cmd << endl;
   }
}

/*
 * Function: helpCommand
 * Usage: helpCommand();
 * ---------------------
 * Lists the available commands.
 */

void helpCommand() {
   cout << "Available commands:" << endl;
   cout << "  enqueue priority str -- Enqueues the string onto the queue" << endl;
   cout << "  dequeue     -- Dequeues and displays the first value" << endl;
   cout << "  peek        -- Peeks at the first element" << endl;
   cout << "  size        -- Prints the size of the queue" << endl;
   cout << "  isEmpty     -- Prints whether the queue is empty" << endl;
   cout << "  clear       -- Clears the queue" << endl;
   cout << "  list        -- List the elements of the queue" << endl;
   cout << "  help        -- List these commands" << endl;
   cout << "  quit        -- Quits the program" << endl;
}

/*
 * Function: listQueue
 * Usage: listQueue(queue);
 * ------------------------
 * Lists the contents of the queue.  This implementation makes an
 * explicit copy to avoid making changes to the argument queue.
 */

void listQueue(const Queue<string> & queue) {
   if (queue.isEmpty()) {
      cout << "Queue is empty" << endl;
   } else {
      Queue<string> q = queue;
      while (!q.isEmpty()) {
         if (q.size() != queue.size()) cout << " ";
         cout << q.dequeue();
      }
      cout << endl;
   }
}

}
