
from CRABClient.UserUtilities import config
config = config()

config.General.requestName = '12june_job_bparked_BPH1_2018A_crab_autojob_MINIAOD_CMSSW10218_2018ULMC_priyanka'
config.General.workArea = '12june_check_bparked_BPH1_2018A_crab_job_MINIAOD_CMSSW10218_2018ULMC_priyanka'
config.General.transferOutputs = True
config.General.transferLogs = False

config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'config_generic_opt_skimmed_.py'
#config.JobType.inputFiles = ['PileupMC_2018.root','DataPileupHistogram2018.root']
config.JobType.outputFiles = ['flatTuple.root']
config.JobType.maxMemoryMB = 2000

config.Data.inputDataset = '/ParkingBPH1/Run2018A-05May2019-v1/MINIAOD'
#config.Data.InputFiles = ['PileupMC_2018.root','DataPileupHistogram2018.root']
config.Data.inputDBS = 'global'
#config.Data.splitting = 'FileBased'
config.Data.splitting = 'LumiBased'
#config.Data.splitting = 'Automatic'
config.Data.unitsPerJob =5

config.Data.lumiMask = '/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions18/13TeV/ReReco/Cert_314472-325175_13TeV_17SeptEarlyReReco2018ABC_PromptEraD_Collisions18_JSON.txt'
#cert_314472-325175_13TeV_17SeptEarlyReReco2018ABC_PromptEraD_Collisions18_JSON.txt
config.Data.runRange = '314472-325175' #Era A
#config.Data.runRange = '317080-319310' #Era B
#config.Data.runRange = '319337-320065' #era C
#config.Data.runRange = '320673-325175' #EraD

config.JobType.allowUndistributedCMSSW = True
#config.Data.ignoreLocality = True
#config.Site.whitelist = ['T2_CH_*', 'T2_UK_*', 'T2_IT_*', 'T2_US_*']


config.Data.outLFNDirBase = '/store/user/psadangi'#'eos/user/p/psadangi'
config.Data.publication = False

config.Site.storageSite = 'T2_IN_TIFR'