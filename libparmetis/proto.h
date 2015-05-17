/*
 * Copyright 1997, Regents of the University of Minnesota
 *
 * proto.h
 *
 * This file contains header files
 *
 * Started 10/19/95
 * George
 *
 * $Id: proto.h 10592 2011-07-16 21:17:53Z karypis $
 *
 */

/* ctrl.c */
METIS_EXPORT ctrl_t *SetupCtrl(pmoptype_et optype, idx_t *options, idx_t ncon, idx_t nparts,
            real_t *tpwgts, real_t *ubvec, MPI_Comm comm);
METIS_EXPORT void SetupCtrl_invtvwgts(ctrl_t *ctrl, graph_t *graph);
METIS_EXPORT void FreeCtrl(ctrl_t **r_ctrl);



/* kmetis.c */
METIS_EXPORT void Global_Partition(ctrl_t *, graph_t *);

/* mmetis.c */

/* gkmetis.c */

/* match.c */
METIS_EXPORT void Match_Global(ctrl_t *, graph_t *);
METIS_EXPORT void Match_Local(ctrl_t *, graph_t *);
METIS_EXPORT void CreateCoarseGraph_Global(ctrl_t *, graph_t *, idx_t);
METIS_EXPORT void CreateCoarseGraph_Local(ctrl_t *, graph_t *, idx_t);


/* initpart.c */
METIS_EXPORT void InitPartition(ctrl_t *, graph_t *);
METIS_EXPORT void KeepPart(ctrl_t *, graph_t *, idx_t *, idx_t);

/* kwayrefine.c */
METIS_EXPORT void ProjectPartition(ctrl_t *, graph_t *);
METIS_EXPORT void ComputePartitionParams(ctrl_t *, graph_t *);
METIS_EXPORT void KWayFM(ctrl_t *, graph_t *, idx_t);
METIS_EXPORT void KWayBalance(ctrl_t *, graph_t *, idx_t);


/* remap.c */
METIS_EXPORT void ParallelReMapGraph(ctrl_t *, graph_t *);
METIS_EXPORT void ParallelTotalVReMap(ctrl_t *, idx_t *, idx_t *, idx_t, idx_t);
METIS_EXPORT idx_t SimilarTpwgts(real_t *, idx_t, idx_t, idx_t);

/* move.c */
METIS_EXPORT graph_t *MoveGraph(ctrl_t *, graph_t *);
/* move.c */
METIS_EXPORT void CheckMGraph(ctrl_t *, graph_t *); 
METIS_EXPORT void ProjectInfoBack(ctrl_t *, graph_t *, idx_t *, idx_t *);
METIS_EXPORT void FindVtxPerm(ctrl_t *, graph_t *, idx_t *);

/* wspace.c */
METIS_EXPORT void AllocateWSpace(ctrl_t *ctrl, size_t nwords);
METIS_EXPORT void AllocateRefinementWorkSpace(ctrl_t *ctrl, idx_t nbrpoolsize);
METIS_EXPORT void FreeWSpace(ctrl_t *);
METIS_EXPORT void *wspacemalloc(ctrl_t *ctrl, size_t nbytes);
METIS_EXPORT idx_t *iwspacemalloc(ctrl_t *ctrl, size_t n);
METIS_EXPORT real_t *rwspacemalloc(ctrl_t *ctrl, size_t n);
METIS_EXPORT ikv_t *ikvwspacemalloc(ctrl_t *ctrl, size_t n);
METIS_EXPORT rkv_t *rkvwspacemalloc(ctrl_t *ctrl, size_t n);
METIS_EXPORT void cnbrpoolReset(ctrl_t *ctrl);
METIS_EXPORT idx_t cnbrpoolGetNext(ctrl_t *ctrl, idx_t nnbrs);


/* ametis.c */
METIS_EXPORT void Adaptive_Partition(ctrl_t *, graph_t *);

/* rmetis.c */


/* wave.c */
METIS_EXPORT real_t WavefrontDiffusion(ctrl_t *, graph_t *, idx_t *);

/* balancemylink.c */
METIS_EXPORT idx_t BalanceMyLink(ctrl_t *, graph_t *, idx_t *, idx_t, idx_t, real_t *, 
          real_t, real_t *, real_t *, real_t);

/* redomylink.c */
METIS_EXPORT void RedoMyLink(ctrl_t *, graph_t *, idx_t *, idx_t, idx_t, real_t *, real_t *, real_t *);

/* initbalance.c */
METIS_EXPORT void Balance_Partition(ctrl_t *, graph_t *);
METIS_EXPORT graph_t *AssembleAdaptiveGraph(ctrl_t *, graph_t *);

/* mdiffusion.c */
METIS_EXPORT idx_t Mc_Diffusion(ctrl_t *, graph_t *, idx_t *, idx_t *, idx_t *, idx_t);
METIS_EXPORT graph_t *ExtractGraph(ctrl_t *, graph_t *, idx_t *, idx_t *, idx_t *);

/* diffutil.c */
METIS_EXPORT void SetUpConnectGraph(graph_t *, matrix_t *, idx_t *);
METIS_EXPORT void Mc_ComputeMoveStatistics(ctrl_t *, graph_t *, idx_t *, idx_t *, idx_t *);
METIS_EXPORT idx_t Mc_ComputeSerialTotalV(graph_t *, idx_t *);
METIS_EXPORT void ComputeLoad(graph_t *, idx_t, real_t *, real_t *, idx_t);
METIS_EXPORT void ConjGrad2(matrix_t *, real_t *, real_t *, real_t, real_t *);
METIS_EXPORT void mvMult2(matrix_t *, real_t *, real_t *);
METIS_EXPORT void ComputeTransferVector(idx_t, matrix_t *, real_t *, real_t *, idx_t);
METIS_EXPORT idx_t ComputeSerialEdgeCut(graph_t *);
METIS_EXPORT idx_t ComputeSerialTotalV(graph_t *, idx_t *);

/* akwayfm.c */
METIS_EXPORT void KWayAdaptiveRefine(ctrl_t *, graph_t *, idx_t);

/* selectq.c */
METIS_EXPORT void Mc_DynamicSelectQueue(ctrl_t *ctrl, idx_t nqueues, idx_t ncon, idx_t subdomain1,
         idx_t subdomain2, idx_t *currentq, real_t *flows, idx_t *from, idx_t *qnum,
         idx_t minval, real_t avgvwgt, real_t maxdiff);
METIS_EXPORT idx_t Mc_HashVwgts(ctrl_t *ctrl, idx_t ncon, real_t *nvwgt);
METIS_EXPORT idx_t Mc_HashVRank(idx_t ncon, idx_t *vwgt);


/* csrmatch.c */
METIS_EXPORT void CSR_Match_SHEM(matrix_t *, idx_t *, idx_t *, idx_t *, idx_t);

/* serial.c */
METIS_EXPORT void Mc_ComputeSerialPartitionParams(ctrl_t *ctrl, graph_t *, idx_t);
METIS_EXPORT void Mc_SerialKWayAdaptRefine(ctrl_t *ctrl, graph_t *, idx_t, idx_t *, real_t *, idx_t);
METIS_EXPORT idx_t AreAllHVwgtsBelow(idx_t, real_t, real_t *, real_t, real_t *, real_t *);
METIS_EXPORT void ComputeHKWayLoadImbalance(idx_t, idx_t, real_t *, real_t *);
METIS_EXPORT void SerialRemap(ctrl_t *ctrl, graph_t *, idx_t, idx_t *, idx_t *, idx_t *, real_t *);
METIS_EXPORT int SSMIncKeyCmp(const void *, const void *);
METIS_EXPORT void Mc_Serial_FM_2WayRefine(ctrl_t *ctrl, graph_t *, real_t *, idx_t);
METIS_EXPORT void Serial_SelectQueue(idx_t, real_t *, real_t *, idx_t *, idx_t *, rpq_t **[2]);
METIS_EXPORT idx_t Serial_BetterBalance(idx_t, real_t *, real_t *, real_t *, real_t *);
METIS_EXPORT real_t Serial_Compute2WayHLoadImbalance(idx_t, real_t *, real_t *);
METIS_EXPORT void Mc_Serial_Balance2Way(ctrl_t *ctrl, graph_t *, real_t *, real_t);
METIS_EXPORT void Mc_Serial_Init2WayBalance(ctrl_t *ctrl, graph_t *, real_t *);
METIS_EXPORT idx_t Serial_SelectQueueOneWay(idx_t, real_t *, real_t *, idx_t, rpq_t **[2]);
METIS_EXPORT void Mc_Serial_Compute2WayPartitionParams(ctrl_t *ctrl, graph_t *);
METIS_EXPORT idx_t Serial_AreAnyVwgtsBelow(idx_t, real_t, real_t *, real_t, real_t *, real_t *);

/* weird.c */
METIS_EXPORT int CheckInputsPartKway(idx_t *vtxdist, idx_t *xadj, idx_t *adjncy, idx_t *vwgt,
        idx_t *adjwgt, idx_t *wgtflag, idx_t *numflag, idx_t *ncon, idx_t *nparts,
        real_t *tpwgts, real_t *ubvec, idx_t *options, idx_t *edgecut, idx_t *part,
        MPI_Comm *comm);
METIS_EXPORT int CheckInputsPartGeomKway(idx_t *vtxdist, idx_t *xadj, idx_t *adjncy, idx_t *vwgt,
        idx_t *adjwgt, idx_t *wgtflag, idx_t *numflag, idx_t *ndims, real_t *xyz, 
        idx_t *ncon, idx_t *nparts, real_t *tpwgts, real_t *ubvec, idx_t *options, 
        idx_t *edgecut, idx_t *part, MPI_Comm *comm);
METIS_EXPORT int CheckInputsPartGeom(idx_t *vtxdist, idx_t *ndims, real_t *xyz, 
        idx_t *part, MPI_Comm *comm);
METIS_EXPORT int CheckInputsAdaptiveRepart(idx_t *vtxdist, idx_t *xadj, idx_t *adjncy,
        idx_t *vwgt, idx_t *vsize, idx_t *adjwgt, idx_t *wgtflag, 
        idx_t *numflag, idx_t *ncon, idx_t *nparts, real_t *tpwgts, 
        real_t *ubvec, real_t *ipc2redist, idx_t *options, idx_t *edgecut, 
        idx_t *part, MPI_Comm *comm);
METIS_EXPORT int CheckInputsNodeND(idx_t *vtxdist, idx_t *xadj, idx_t *adjncy, 
        idx_t *numflag, idx_t *options, idx_t *order, idx_t *sizes,
        MPI_Comm *comm);
METIS_EXPORT int CheckInputsPartMeshKway(idx_t *elmdist, idx_t *eptr, idx_t *eind, idx_t *elmwgt,
        idx_t *wgtflag, idx_t *numflag, idx_t *ncon, idx_t *ncommon, idx_t *nparts,
        real_t *tpwgts, real_t *ubvec, idx_t *options, idx_t *edgecut, idx_t *part,
        MPI_Comm *comm);
METIS_EXPORT void PartitionSmallGraph(ctrl_t *, graph_t *);


/* mesh.c */

/* pspases.c */
METIS_EXPORT graph_t *AssembleEntireGraph(ctrl_t *, idx_t *, idx_t *, idx_t *);

/* node_refine.c */
METIS_EXPORT void AllocateNodePartitionParams(ctrl_t *, graph_t *);
METIS_EXPORT void ComputeNodePartitionParams(ctrl_t *, graph_t *);
METIS_EXPORT void UpdateNodePartitionParams(ctrl_t *, graph_t *);
METIS_EXPORT void KWayNodeRefine_Greedy(ctrl_t *ctrl, graph_t *graph, idx_t npasses, real_t ubfrac);
METIS_EXPORT void KWayNodeRefine2Phase(ctrl_t *ctrl, graph_t *graph, idx_t npasses, real_t ubfrac);
METIS_EXPORT void KWayNodeRefineInterior(ctrl_t *ctrl, graph_t *graph, idx_t npasses, real_t ubfrac);
METIS_EXPORT void PrintNodeBalanceInfo(ctrl_t *, idx_t, idx_t *, idx_t *, char *);


/* initmsection.c */
METIS_EXPORT void InitMultisection(ctrl_t *, graph_t *);
graph_t *AssembleMultisectedGraph(ctrl_t *, graph_t *);


/* ometis.c */
METIS_EXPORT void MultilevelOrder(ctrl_t *ctrl, graph_t *graph, idx_t *order, idx_t *sizes);
METIS_EXPORT void Order_Partition_Multiple(ctrl_t *ctrl, graph_t *graph);
METIS_EXPORT void Order_Partition(ctrl_t *ctrl, graph_t *graph, idx_t *nlevels, idx_t clevel);
METIS_EXPORT void LabelSeparators(ctrl_t *, graph_t *, idx_t *, idx_t *, idx_t *, idx_t *);
METIS_EXPORT void CompactGraph(ctrl_t *, graph_t *, idx_t *);
METIS_EXPORT void LocalNDOrder(ctrl_t *, graph_t *, idx_t *, idx_t);


/* xyzpart.c */
METIS_EXPORT void Coordinate_Partition(ctrl_t *, graph_t *, idx_t, real_t *, idx_t);
METIS_EXPORT void IRBinCoordinates(ctrl_t *ctrl, graph_t *graph, idx_t ndims, real_t *xyz, 
         idx_t nbins, idx_t *bxyz);
METIS_EXPORT void RBBinCoordinates(ctrl_t *ctrl, graph_t *graph, idx_t ndims, real_t *xyz, 
         idx_t nbins, idx_t *bxyz);
METIS_EXPORT void SampleSort(ctrl_t *, graph_t *, ikv_t *);
METIS_EXPORT void PseudoSampleSort(ctrl_t *, graph_t *, ikv_t *);


/* stat.c */
METIS_EXPORT void ComputeSerialBalance(ctrl_t *, graph_t *, idx_t *, real_t *);
METIS_EXPORT void ComputeParallelBalance(ctrl_t *, graph_t *, idx_t *, real_t *);
METIS_EXPORT void Mc_PrintThrottleMatrix(ctrl_t *, graph_t *, real_t *);
METIS_EXPORT void PrintPostPartInfo(ctrl_t *ctrl, graph_t *graph, idx_t movestats);
METIS_EXPORT void ComputeMoveStatistics(ctrl_t *, graph_t *, idx_t *, idx_t *, idx_t *);

/* debug.c */
METIS_EXPORT void PrintVector(ctrl_t *, idx_t, idx_t, idx_t *, char *);
METIS_EXPORT void PrintVector2(ctrl_t *, idx_t, idx_t, idx_t *, char *);
METIS_EXPORT void PrintPairs(ctrl_t *, idx_t, ikv_t *, char *);
METIS_EXPORT void PrintGraph(ctrl_t *, graph_t *);
METIS_EXPORT void PrintGraph2(ctrl_t *, graph_t *);
METIS_EXPORT void PrintSetUpInfo(ctrl_t *ctrl, graph_t *graph);
METIS_EXPORT void PrintTransferedGraphs(ctrl_t *, idx_t, idx_t *, idx_t *, idx_t *, idx_t *, idx_t *);
METIS_EXPORT void WriteMetisGraph(idx_t, idx_t *, idx_t *, idx_t *, idx_t *);


/* comm.c */
METIS_EXPORT void CommSetup(ctrl_t *, graph_t *);
METIS_EXPORT void CommUpdateNnbrs(ctrl_t *ctrl, idx_t nnbrs);
METIS_EXPORT void CommInterfaceData(ctrl_t *ctrl, graph_t *graph, idx_t *data, idx_t *recvvector);
METIS_EXPORT void CommChangedInterfaceData(ctrl_t *ctrl, graph_t *graph, idx_t nchanged,
         idx_t *changed, idx_t *data, ikv_t *sendpairs, ikv_t *recvpairs);
METIS_EXPORT idx_t GlobalSEMax(ctrl_t *, idx_t);
METIS_EXPORT idx_t GlobalSEMaxComm(MPI_Comm comm, idx_t value);
METIS_EXPORT idx_t GlobalSEMin(ctrl_t *, idx_t);
METIS_EXPORT idx_t GlobalSEMinComm(MPI_Comm comm, idx_t value);
METIS_EXPORT idx_t GlobalSESum(ctrl_t *, idx_t);
METIS_EXPORT idx_t GlobalSESumComm(MPI_Comm comm, idx_t value);
METIS_EXPORT real_t GlobalSEMaxFloat(ctrl_t *, real_t);
METIS_EXPORT real_t GlobalSEMinFloat(ctrl_t *, real_t);
METIS_EXPORT real_t GlobalSESumFloat(ctrl_t *, real_t);

/* util.c */
METIS_EXPORT void myprintf(ctrl_t *ctrl, char *f_str,...);
METIS_EXPORT void rprintf(ctrl_t *ctrl, char *f_str,...);
METIS_EXPORT void mypridx_tf(ctrl_t *, char *f_str,...);
METIS_EXPORT void rpridx_tf(ctrl_t *, char *f_str,...);
METIS_EXPORT idx_t BSearch(idx_t, idx_t *, idx_t);
METIS_EXPORT void RandomPermute(idx_t, idx_t *, idx_t);
METIS_EXPORT void FastRandomPermute(idx_t, idx_t *, idx_t);
METIS_EXPORT idx_t ispow2(idx_t);
METIS_EXPORT idx_t log2Int(idx_t);
METIS_EXPORT void BucketSortKeysDec(idx_t, idx_t, idx_t *, idx_t *);
METIS_EXPORT real_t BetterVBalance(idx_t, real_t *, real_t *, real_t *);
METIS_EXPORT idx_t IsHBalanceBetterTT(idx_t, real_t *, real_t *, real_t *, real_t *);
METIS_EXPORT idx_t IsHBalanceBetterFT(idx_t, real_t *, real_t *, real_t *, real_t *);
METIS_EXPORT void GetThreeMax(idx_t, real_t *, idx_t *, idx_t *, idx_t *);
METIS_EXPORT size_t rargmax_strd(size_t n, real_t *x, size_t incx);
METIS_EXPORT size_t rargmin_strd(size_t n, real_t *x, size_t incx);
METIS_EXPORT size_t rargmax2(size_t n, real_t *x);
METIS_EXPORT real_t ravg(size_t n, real_t *x);
METIS_EXPORT real_t rfavg(size_t n, real_t *x);

/* grsetup.c */
METIS_EXPORT graph_t *SetupGraph(ctrl_t *ctrl, idx_t ncon, idx_t *vtxdist, idx_t *xadj,
             idx_t *vwgt, idx_t *vsize, idx_t *adjncy, idx_t *adjwgt, 
             idx_t wgtflag);
METIS_EXPORT void SetupGraph_nvwgts(ctrl_t *ctrl, graph_t *graph);
METIS_EXPORT graph_t *CreateGraph(void);
METIS_EXPORT void InitGraph(graph_t *);
METIS_EXPORT void FreeGraph(graph_t *graph);
METIS_EXPORT void FreeNonGraphFields(graph_t *graph);
METIS_EXPORT void FreeNonGraphNonSetupFields(graph_t *graph);
METIS_EXPORT void FreeInitialGraphAndRemap(graph_t *graph);
METIS_EXPORT void ChangeNumbering(idx_t *, idx_t *, idx_t *, idx_t *, idx_t, idx_t, idx_t);
METIS_EXPORT void ChangeNumberingMesh(idx_t *elmdist, idx_t *eptr, idx_t *eind,
                         idx_t *xadj, idx_t *adjncy, idx_t *part,
			 idx_t npes, idx_t mype, idx_t from);

/* timer.c */
METIS_EXPORT void InitTimers(ctrl_t *);
METIS_EXPORT void PrintTimingInfo(ctrl_t *);
METIS_EXPORT void PrintTimer(ctrl_t *, timer, char *);



/* parmetis.c */
METIS_EXPORT void ChangeToFortranNumbering(idx_t *, idx_t *, idx_t *, idx_t, idx_t);


/* msetup.c */
METIS_EXPORT mesh_t *SetUpMesh(idx_t *etype, idx_t *ncon, idx_t *elmdist, idx_t *elements,
      idx_t *elmwgt, idx_t *wgtflag, MPI_Comm *comm);
METIS_EXPORT mesh_t *CreateMesh(void);
METIS_EXPORT void InitMesh(mesh_t *mesh);


/* gkmpi.c */
METIS_EXPORT int gkMPI_Comm_size(MPI_Comm comm, idx_t *size);
METIS_EXPORT int gkMPI_Comm_rank(MPI_Comm comm, idx_t *rank);
METIS_EXPORT int gkMPI_Get_count(MPI_Status *status, MPI_Datatype datatype,
        idx_t *count);
METIS_EXPORT int gkMPI_Send(void *buf, idx_t count, MPI_Datatype datatype, idx_t dest,
        idx_t tag, MPI_Comm comm);
METIS_EXPORT int gkMPI_Recv(void *buf, idx_t count, MPI_Datatype datatype,
        idx_t source, idx_t tag, MPI_Comm comm, MPI_Status *status);
METIS_EXPORT int gkMPI_Isend(void *buf, idx_t count, MPI_Datatype datatype, idx_t dest,
        idx_t tag, MPI_Comm comm, MPI_Request *request);
METIS_EXPORT int gkMPI_Irecv(void *buf, idx_t count, MPI_Datatype datatype,
        idx_t source, idx_t tag, MPI_Comm comm, MPI_Request *request);
METIS_EXPORT int gkMPI_Wait(MPI_Request *request, MPI_Status *status);
METIS_EXPORT int gkMPI_Waitall(idx_t count, MPI_Request *array_of_requests, 
        MPI_Status *array_of_statuses);
METIS_EXPORT int gkMPI_Barrier(MPI_Comm comm);
METIS_EXPORT int gkMPI_Bcast(void *buffer, idx_t count, MPI_Datatype datatype,
        idx_t root, MPI_Comm comm);
METIS_EXPORT int gkMPI_Reduce(void *sendbuf, void *recvbuf, idx_t count,
        MPI_Datatype datatype, MPI_Op op, idx_t root, MPI_Comm comm);
METIS_EXPORT int gkMPI_Allreduce(void *sendbuf, void *recvbuf, idx_t count,
        MPI_Datatype datatype, MPI_Op op, MPI_Comm comm);
METIS_EXPORT int gkMPI_Scan(void *sendbuf, void *recvbuf, idx_t count,
        MPI_Datatype datatype, MPI_Op op, MPI_Comm comm);
METIS_EXPORT int gkMPI_Allgather(void *sendbuf, idx_t sendcount,
        MPI_Datatype sendtype, void *recvbuf, idx_t recvcount,
        MPI_Datatype recvtype, MPI_Comm comm);
METIS_EXPORT int gkMPI_Alltoall(void *sendbuf, idx_t sendcount,
        MPI_Datatype sendtype, void *recvbuf, idx_t recvcount,
        MPI_Datatype recvtype, MPI_Comm comm);
METIS_EXPORT int gkMPI_Alltoallv(void *sendbuf, idx_t *sendcounts,
        idx_t *sdispls, MPI_Datatype sendtype, void *recvbuf, 
        idx_t *recvcounts, idx_t *rdispls, MPI_Datatype recvtype, 
        MPI_Comm comm);
METIS_EXPORT int gkMPI_Allgatherv(void *sendbuf, idx_t sendcount, MPI_Datatype sendtype, 
        void *recvbuf, idx_t *recvcounts, idx_t *rdispls, 
        MPI_Datatype recvtype, MPI_Comm comm);
METIS_EXPORT int gkMPI_Scatterv(void *sendbuf, idx_t *sendcounts, idx_t *sdispls,
        MPI_Datatype sendtype, void *recvbuf, idx_t recvcount,
        MPI_Datatype recvtype, idx_t root, MPI_Comm comm);
METIS_EXPORT int gkMPI_Gatherv(void *sendbuf, idx_t sendcount, MPI_Datatype sendtype,
        void *recvbuf, idx_t *recvcounts, idx_t *displs, MPI_Datatype recvtype,
        idx_t root, MPI_Comm comm);
METIS_EXPORT int gkMPI_Comm_split(MPI_Comm comm, idx_t color, idx_t key,
        MPI_Comm *newcomm);
METIS_EXPORT int gkMPI_Comm_free(MPI_Comm *comm);
METIS_EXPORT int gkMPI_Finalize();



