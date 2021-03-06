#include <iostream>
#include "ConcurrentHashMap.hpp"
#include <unistd.h>
using namespace std;



void *add(void* h){

  ConcurrentHashMap* ch = (ConcurrentHashMap*) h ;
  usleep(rand() % 10000);
  ch->addAndInc("gola");
  return NULL;

}

void *add1(void* h){

  ConcurrentHashMap* ch = (ConcurrentHashMap*) h ;
  //cout << ch->member("hola2");
  usleep(rand() % 10000);
  ch->addAndInc("hola");
  return NULL;

}
void *add2(void* h){

  ConcurrentHashMap* ch = (ConcurrentHashMap*) h ;
  //cout << ch->member("hola3");
  usleep(rand() % 10000);
  ch->addAndInc("lola");
  return NULL;

}
void *add3(void* h){

  ConcurrentHashMap* ch = (ConcurrentHashMap*) h ;
  //c//out << ch->member("hola4");
  usleep(rand() % 10000);
  ch->addAndInc("coca");

  return NULL;

}




int main(void) {

  ConcurrentHashMap h;
  ConcurrentHashMap h2;

  pthread_t threads[200]; int tid;

  for (tid = 0; tid < 50; tid++) {
    pthread_create(&threads[tid],NULL,add,&h);
    pthread_create(&threads[50+tid],NULL,add1,&h);
    pthread_create(&threads[100+tid],NULL,add2,&h2);
    pthread_create(&threads[150+tid],NULL,add3,&h2);
  }

  h.print_tabla();
  h2.print_tabla();
  pair<string,unsigned int> s = h.maximum(10);
  cout << "<" << s.first << " , " << s.second << ">" << endl;
  pair<string,unsigned int> s2 = h2.maximum(10);
  cout << "<" << s2.first << " , " << s2.second << ">" << endl;

  h.print_tabla();
  h2.print_tabla();
  s = h.maximum(10);
  s2 = h.maximum(10);
  cout << "<" << s.first << " , " << s.second << ">" << endl;
  cout << "<" << s2.first << " , " << s2.second << ">" << endl;

  for (tid = 0; tid < 200; tid++) {
    pthread_join(threads[tid],NULL);
  }
  h.print_tabla();
  h2.print_tabla();

  cout << "--------------- Creando nueva tabla para testear Count_words(list<string>)-----------" << endl;

  ConcurrentHashMap palabras;


  list<string> l;
  l.push_back("file1");
  l.push_back("file2");
  l.push_back("file3");
  l.push_back("file4");

  palabras = count_words(l);
  int i;
  for (i = 0; i < 26; i++) {
    for (auto it = palabras.tabla[i]->CrearIt(); it.HaySiguiente(); it.Avanzar()) {
      auto t = it.Siguiente();
      cout << t.first << " " << t.second << endl;
    }
  }
  pair<string,unsigned int> max = palabras.maximum(26);
  cout << "<" << max.first << " , " << max.second << ">" << endl;

  cout << "-----------------Creando nueva tabla para testear Count_words(n, list<string>)-----------" << endl;

  ConcurrentHashMap words;
  list<string> l2;
  l2.push_back("file1");
  l2.push_back("file2");
  l2.push_back("file3");
  l2.push_back("file4");

  unsigned int k = 2;
  words = count_words(k,l2);
  for (i = 0; i < 26; i++) {
    for (auto it = words.tabla[i]->CrearIt(); it.HaySiguiente(); it.Avanzar()) {
      auto t = it.Siguiente();
      cout << t.first << " " << t.second << endl;
    }
  }

  pair<string , unsigned int > m = maximum(2,2,l2);
  cout << "<" << m.first << " " << m.second << ">" << endl;

  ConcurrentHashMap vacio;
  ConcurrentHashMap h3 = vacio;

  h3.print_tabla();

  h3 = palabras;

  h3.print_tabla();

	return 0;
}
