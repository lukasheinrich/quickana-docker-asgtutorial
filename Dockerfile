FROM lukasheinrich/alrb_athanalysisbase_2_4_8_complete
COPY . /analysis
WORKDIR /analysis
RUN bash -c 'source setup.sh && cd MyAnalysis/cmt && cmt br cmt config && cmt br cmt make' 
