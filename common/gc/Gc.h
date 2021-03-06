//
//  Gc.hpp
//  vm
//
//  Created by yangjiandong on 10/25/15.
//  Copyright © 2015 chunquedong. All rights reserved.
//

#ifndef Gc_hpp
#define Gc_hpp

#include "gcobj.h"
#include "gci.h"

#include <stdio.h>
//#include "vm.h"
#include <list>
#include <vector>
#include <set>
#include <mutex>
#include <map>
#include "Bitmap.hpp"
#include <thread>
#include <atomic>


#define GC_USE_BITMAP 0

class Gc : public Collector {
    std::list<GcObj*> pinObjs;

#if GC_USE_BITMAP
    Bitmap allRefs;
#else
    std::map<void *, bool> allRefs;
#endif
    std::vector<GcObj*> markStack;
    
    std::vector<GcObj*> dirtyList;
    
    std::recursive_mutex lock;
    std::atomic<bool> isStopWorld;
    int marker;
    bool running;
    std::atomic<bool> isMarking;
    std::thread *gcThread;
    std::mutex cdLock;
    std::condition_variable condition;
public:
    //GcSupport *gcSupport;
    
    long collectLimit;
    long lastAllocSize;
    long allocSize;
    int trace;
    
public:

    Gc(GcSupport *support);
    ~Gc();
    
    bool isRef(void *p);
    
    GcObj* alloc(void *type, int size);
    
    void pinObj(GcObj* obj);
    void unpinObj(GcObj* obj);
    
    void onVisit(GcObj* obj);
 
    void collect();
    
    void setDirty(GcObj *obj);
    
    void gcThreadRun();
    
    bool isStopTheWorld();
private:
    void setMarking(bool m);
    void doCollect();
    
    void puaseWorld(bool bloking = true);
    void resumeWorld();
    
    void beginGc();
    void endGc();
    
    //void mergeNewAlloc();
    bool mark();
    void getRoot();
    void sweep();
//    bool remark();
    void remove(GcObj* obj);
    
    bool markNode(GcObj* obj);
};

#endif /* Gc_hpp */
