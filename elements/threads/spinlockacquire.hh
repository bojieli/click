#ifndef CLICK_SPINLOCKACQUIRE_HH
#define CLICK_SPINLOCKACQUIRE_HH
#include <click/element.hh>
#include <click/sync.hh>
CLICK_DECLS

/*
 * =c
 * SpinlockAcquire(LOCK)
 * =s threads
 * acquires spinlock
 * =d
 * Acquires the spinlock named LOCK. LOCK must be defined in a SpinlockInfo
 * element.
 * =a SpinlockInfo, SpinlockRelease
 */

class SpinlockAcquire : public Element {
  Spinlock *_lock;
 
public:
  SpinlockAcquire()			: _lock(0) {}
  ~SpinlockAcquire()			{}

  const char *class_name() const	{ return "SpinlockAcquire"; }
  
  int configure(Vector<String> &, ErrorHandler *);
  
  Packet *simple_action(Packet *p)  	{ _lock->acquire(); return p; }
};

CLICK_ENDDECLS
#endif