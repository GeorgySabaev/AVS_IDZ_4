#include <pthread.h>
#include <queue>
#include <iostream>
#include <string>
#include <semaphore.h>
#include <sstream>
#include <vector>

sem_t gallery;
sem_t paintings[5];

pthread_mutex_t output_mutex;
void print(std::string s){
  pthread_mutex_lock(&output_mutex);
  std::cout << s;
  pthread_mutex_unlock(&output_mutex);
}

class Person {
 public:
  int name;
  bool has_entered;
  Person(){
    name = std::rand() % 900 + 100;
  }
  void visit_gallery(){
    sem_wait(&gallery);
    while(std::rand() % 10 != 0){
      int painting_number = std::rand() % 5;
      sem_wait(&paintings[painting_number]);
      std::stringstream message;
      message << "Person " << name << " observed painting " << painting_number << ".\n";
      print(message.str());
      sem_post(&paintings[painting_number]);
    }
    std::stringstream message;
    message << "Person " << name << " left the gallery.\n";
    print(message.str());
    sem_post(&gallery);
  }
};

void* start_visit(void* arg) {
  Person p = *static_cast<Person*>(arg);
  p.visit_gallery();
  return nullptr;
}

int main(){
  for (auto & painting : paintings) {
    sem_init(&painting, 0, 10);
  }
  sem_init(&gallery, 0, 50);
  for (int i = 0; i < 300; ++i) {
    Person *p = new Person();
    pthread_t *visit = nullptr;
    pthread_create(visit, nullptr, start_visit, p);
  }
  pthread_exit(NULL);
}