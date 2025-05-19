#ifndef KEY_EVENT_H
#define KEY_EVENT_H
class KeyEvent {
 public:
  int key;
  int scancode;
  int action;
  int mods;

  KeyEvent();
};
#endif
