#ifndef MYANALYSIS_MYALGORITHM_H
#define MYANALYSIS_MYALGORITHM_H 1

#include "AthenaBaseComps/AthHistogramAlgorithm.h"
#include "GaudiKernel/ToolHandle.h" //included under assumption you'll want to use some tools! Remove if you don't!



class MyAlgorithm: public ::AthHistogramAlgorithm { 
 public: 
  MyAlgorithm( const std::string& name, ISvcLocator* pSvcLocator );
  virtual ~MyAlgorithm(); 

  virtual StatusCode  initialize();
  virtual StatusCode  execute();
  virtual StatusCode  finalize();

 private: 

}; 

#endif //> !MYANALYSIS_MYALGORITHM_H
