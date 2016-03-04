FROM lukasheinrich/atlas-athanalysisbase-2.3.45
COPY . /analysis
WORKDIR /analysis
RUN bash -c 'source setup.sh && cd MyAnalysis/cmt && cmt br cmt config && cmt br cmt make' 
