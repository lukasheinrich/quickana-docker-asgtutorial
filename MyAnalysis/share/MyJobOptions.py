import AthenaPoolCnvSvc.ReadAthenaPool

# point this to the actual file you are using
svcMgr.EventSelector.InputCollections = [ os.getenv ("ROOTCORE_TEST_FILE") ]

algSeq = CfgMgr.AthSequencer("AthAlgSeq")

alg = CfgMgr.MyAlgorithm()

# Define your output file name and stream name
rootStreamName = "MyHistoStream"
rootFileName   = "myHistos.root"
alg.RootStreamName   = rootStreamName
alg.RootDirName      = "/"

# future algorithm configuration goes here

algSeq += alg


quickAna = CfgMgr.ana__QuickAna()
quickAna.electronDef = "default"
ToolSvc += quickAna

alg.quickAna = quickAna

# set the number of events
theApp.EvtMax = -1

# ====================================================================
# Define your output root file using MultipleStreamManager
# ====================================================================
from OutputStreamAthenaPool.MultipleStreamManager import MSMgr
MyFirstHistoXAODStream = MSMgr.NewRootStream( rootStreamName, rootFileName )
