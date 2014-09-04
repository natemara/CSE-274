/*
 * random_queue.cpp
 *
 *  Created on: Sep 4, 2014
 *      Author: maranj
 */

#include <stdlib.h>
#include "random_queue.h"

RandomQueue::RandomQueue(){
  // Complexity is O(n)
  this->size = 0;
  for (int i = 0; i < sizeof(this->array); i++) {
    this->array[i] = 0;
  }
}

RandomQueue::~RandomQueue() {
}

bool RandomQueue::Enqueue(char item) {
  // Complexity is O(n)
  for (int i = 0; i < sizeof(this->array); i++) {
    if (this->array[i] == 0) {
      this->array[i] = item;
      this->size++;
      return true;
    }
  }
  return false;
}

char RandomQueue::Dequeue() {
  // Complexity is O(n)
  int index = rand() % this->size;
  char result = this->array[index];
  this->size--;
  for (int i = 0; i < sizeof(this->array) - 1; i++) {
    this->array[i] = this->array[i + 1];
    if (this->array[i + 1]) {
      break;
    }
  }
  this->array[sizeof(this->array)-1] = 0;
  return result;
}


