FROM lukasheinrich/alrb_athanalysisbase_2_4_18_complete
COPY . /analysis
WORKDIR /analysis
RUN bash -i -l -c 'setup_alrb && asetup AthAnalysisBase,2.4.18,here && cmt find_packages && cmt compile'
