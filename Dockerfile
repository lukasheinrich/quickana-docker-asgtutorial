#FROM lukasheinrich/athanalysisbase-2.3.41
FROM forwill
RUN yum install -y libX11-devel libXpm-devel libXft-devel libXext-devel
RUN ln -s /usr/local/bin/g++ /usr/local/bin/lcg-g++-4.9.3
COPY . /analysis
WORKDIR /analysis
RUN bash -c 'source setup.sh && cd MyAnalysis/cmt && cmt br cmt config && cmt br cmt make' 
