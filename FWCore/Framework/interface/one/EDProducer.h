#ifndef FWCore_Framework_one_EDProducer_h
#define FWCore_Framework_one_EDProducer_h
// -*- C++ -*-
//
// Package:     FWCore/Framework
// Class  :     edm::one::EDProducer
// 
/**\class edm::one::EDProducer EDProducer.h "FWCore/Framework/interface/one/EDProducer.h"

 Description: [one line class summary]

 Usage:
    <usage>

*/
//
// Original Author:  Chris Jones
//         Created:  Thu, 09 May 2013 19:53:55 GMT
//

// system include files

// user include files
#include "FWCore/Framework/interface/one/producerAbilityToImplementor.h"

// forward declarations
namespace edm {
  namespace one {
    template< typename... T>
    class EDProducer : public virtual EDProducerBase,
                       public producer::AbilityToImplementor<T>::Type... { 
    public:
      EDProducer() = default;
#ifdef __INTEL_COMPILER
      virtual ~EDProducer() = default;
#endif
      //
      
      // ---------- const member functions ---------------------
      bool wantsGlobalRuns() const final {
        return WantsGlobalRunTransitions<T...>::value;
      }
      bool wantsGlobalLuminosityBlocks() const final {
        return WantsGlobalLuminosityBlockTransitions<T...>::value;
      }

      bool hasAbilityToProduceInRuns() const final {
        return HasAbilityToProduceInRuns<T...>::value;
      }

      bool hasAbilityToProduceInLumis() const final {
        return HasAbilityToProduceInLumis<T...>::value;
      }

      SerialTaskQueue* globalRunsQueue() final { return globalRunsQueue_.queue();}
      SerialTaskQueue* globalLuminosityBlocksQueue() final { return globalLuminosityBlocksQueue_.queue();}

      // ---------- static member functions --------------------
      
      // ---------- member functions ---------------------------
      
    private:
      EDProducer(const EDProducer&) = delete;
      const EDProducer& operator=(const EDProducer&) = delete;
      
      // ---------- member data --------------------------------
      impl::OptionalSerialTaskQueueHolder<WantsGlobalRunTransitions<T...>::value> globalRunsQueue_;
      impl::OptionalSerialTaskQueueHolder<WantsGlobalLuminosityBlockTransitions<T...>::value> globalLuminosityBlocksQueue_;
    };
    
  }
}


#endif
