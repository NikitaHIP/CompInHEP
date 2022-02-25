void ex5task1()
{

	TFile *f = new TFile("datafile.root", "RECREATE");
	TTree *T = new TTree("T","simple tree");
	double x;
	
	T->Branch("x",&x,"x/D");
	UShort_t N;
	TRandom2 *rand = new TRandom2(1);
	
	for (N = 0; N < 1000; N++)
	{
		x = rand->Gaus(10,1);
		cout << x << endl;
		T->Fill();
	}
	
	f->Write();
	f->Close();
}
