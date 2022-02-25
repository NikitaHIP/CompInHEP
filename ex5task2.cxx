void ex5task2()
{
	TCanvas *c1 = new TCanvas();
	
	TFile *f = new TFile("datafile.root","READ");
	
	TTree *T = (TTree*)f->Get("T");
	
	double x;
	
	T->SetBranchAddress("x", &x);
	
	int entries = T->GetEntries();
	
	cout << entries << endl;
	
	TH1F *hist = new TH1F("hist", "", 100, 0, 25);
	
	for(int i = 0; i < entries; i++)
	{
		T->GetEntry(i);
		
		cout << x << endl;
		
		hist->Fill(x);
	}
	
	hist->SetFillColor(kYellow-9);
	hist->SetLineWidth(3);
	hist->SetLineColor(kBlack);
	
	hist->GetXaxis()->SetTitle("Distribution");
	hist->GetYaxis()->SetTitle("Entries");
	
	hist->GetXaxis()->SetTitleSize(0.05);
	hist->GetYaxis()->SetTitleSize(0.05);
	hist->GetXaxis()->SetLabelSize(0.05);
	hist->GetYaxis()->SetLabelSize(0.05);
	
	TF1 *fit = new TF1("fit", "gaus", 0,25);
	
	fit->SetLineWidth(4);
	fit->SetLineStyle(2);
	
	fit->SetParameter(0, 80);
	fit->SetParameter(2, 10);
	fit->SetParameter(2, 1);
	
	c1-> SetTickx();
	c1-> SetTicky();
	hist->SetStats(0);
	hist->Draw();
	hist->Fit("fit", "R");
	
	TLegend *leg = new TLegend(0.6,0.7,0.9,0.9);
	leg->SetBorderSize(1);
	leg->AddEntry(hist, "Generated Data", "f");
	leg->AddEntry(fit, "Fit Function", "l");
	leg->Draw();
		
}

