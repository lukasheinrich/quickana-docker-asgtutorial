import ROOT
import sys
if len(sys.argv) < 3: sys.exit(1)
f = ROOT.TFile.Open(sys.argv[1])
pt_histo = f.Get('el_pt')
c = ROOT.TCanvas()
pt_histo.Draw()
c.SaveAs(sys.argv[2])
