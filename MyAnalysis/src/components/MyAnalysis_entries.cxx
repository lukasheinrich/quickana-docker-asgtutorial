
#include "GaudiKernel/DeclareFactoryEntries.h"

#include "../MyAlgorithm.h"

DECLARE_ALGORITHM_FACTORY( MyAlgorithm )

DECLARE_FACTORY_ENTRIES( MyAnalysis ) 
{
  DECLARE_ALGORITHM( MyAlgorithm );
}
