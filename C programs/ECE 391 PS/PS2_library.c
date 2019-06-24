#include <linux/spinlock.h>
#define MAX_STACK_CAP 15
// You may add up to 9 elements to this struct.
// The type of synchronization primitive you may use is spinlock.
typedef struct ps_enter_exit_lock{
  spinlock_t spl = SPIN_LOCK_UNLOCKED;
  volatile int std_cnt = 0;
  volatile int lib_cnt = 0;
  volatile int prof_cnt = 0;
  volatile int std_wait_cnt = 0;
  volatile int lib_wait_cnt = 0;
  volatile int prof_wait_cnt = 0;

}ps_lock;
int librarian_enter(ps_lock* ps) {
  if(ps==NULL)  return -1;
  spin_lock_irqsave(&(ps->spl));
  //critical section
  while(1){
    //if prof or students are in stack or libarians are at max (15), wait
    if(ps->prof_cnt + ps->std_cnt > 0 || ps->lib_cnt == MAX_STACK_CAP) {
  		ps->lib_wait_cnt++;
      break;
  	}
  }

  //otherwise dec wait and increment count
  else {
		if(ps->lib_wait_cnt > 0) ps->lib_wait_cnt--;
		ps->lib_cnt++;
	}

  spin_unlock_irqsave(&(ps->spl));
  return 0;
}
int librarian_exit(ps_lock* ps) {
  if(ps==NULL)  return -1;
  spin_lock_irqsave(&(ps->spl));
  //critical section
  //make sure nonzero num librarians in stacks
  if(ps->lib_cnt > 0)
    ps->lib_cnt--;

  spin_unlock_irqsave(&(ps->spl));
  return 0;
}
int student_enter(ps_lock* ps) {
  if(ps==NULL)  return -1;

  while(1){
    spin_lock_irqsave(&(ps->spl));
    //critical section
    //students can't be in stacks same time as librarian (wait if there is)
    if(ps->lib_cnt > 0 || (ps->prof_cnt + ps->std_cnt == MAX_STACK_CAP){
      ps->std_wait_cnt++;
    }
    else{
      if(ps->std_wait_cnt > 0) ps->std_wait_cnt--;
      ps->std_cnt++;
    }
    spin_unlock_irqsave(&(ps->spl));
  }

  return 0;

}
int student_exit(ps_lock* ps) {
  if(ps==NULL)  return -1;
  spin_lock_irqsave(&(ps->spl));
  if(ps->std_cnt > 0){
    ps->std_cnt--;
  }
  spin_unlock_irqsave(&(ps->spl));
  return 0;
}
int professor_enter(ps_lock* ps) {
  if(ps==NULL)  return -1;
  while(1){
    spin_lock_irqsave(&(ps->spl));
    //critical section
    //students can't be in stacks same time as librarian (wait if there is)
    if(ps->lib_cnt > 0 || (ps->prof_cnt + ps->std_cnt == MAX_STACK_CAP){
      ps->prof_wait_cnt++;
    }
    else{
      if(ps->prof_wait_cnt > 0) ps->prof_wait_cnt--;
      ps->prof_cnt++;
    }
    spin_unlock_irqsave(&(ps->spl));
  }

  return 0;
}
int professor_exit(ps_lock* ps) {
  if(ps==NULL)  return -1;
  spin_lock_irqsave(&(ps->spl));
  if(ps->prof_cnt > 0){
    ps->prof_cnt--;
  }
  spin_unlock_irqsave(&(ps->spl));
  return 0;
}
