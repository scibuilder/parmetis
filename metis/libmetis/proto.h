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
 * $Id: proto.h 13933 2013-03-29 22:20:46Z karypis $
 *
 */

#ifndef _LIBMETIS_PROTO_H_
#define _LIBMETIS_PROTO_H_

/* auxapi.c */

/* balance.c */
METIS_EXPORT void Balance2Way(ctrl_t *ctrl, graph_t *graph, real_t *ntpwgts);
METIS_EXPORT void Bnd2WayBalance(ctrl_t *ctrl, graph_t *graph, real_t *ntpwgts);
METIS_EXPORT void General2WayBalance(ctrl_t *ctrl, graph_t *graph, real_t *ntpwgts);
METIS_EXPORT void McGeneral2WayBalance(ctrl_t *ctrl, graph_t *graph, real_t *ntpwgts);


/* bucketsort.c */
METIS_EXPORT void BucketSortKeysInc(ctrl_t *ctrl, idx_t n, idx_t max, idx_t *keys,
         idx_t *tperm, idx_t *perm);


/* checkgraph.c */
METIS_EXPORT int CheckGraph(graph_t *graph, int numflag, int verbose);
METIS_EXPORT int CheckInputGraphWeights(idx_t nvtxs, idx_t ncon, idx_t *xadj, idx_t *adjncy,
        idx_t *vwgt, idx_t *vsize, idx_t *adjwgt);
graph_t *FixGraph(graph_t *graph);


/* coarsen.c */
METIS_EXPORT graph_t *CoarsenGraph(ctrl_t *ctrl, graph_t *graph);
METIS_EXPORT graph_t *CoarsenGraphNlevels(ctrl_t *ctrl, graph_t *graph, idx_t nlevels);
METIS_EXPORT idx_t Match_RM(ctrl_t *ctrl, graph_t *graph);
METIS_EXPORT idx_t Match_SHEM(ctrl_t *ctrl, graph_t *graph);
METIS_EXPORT idx_t Match_2Hop(ctrl_t *ctrl, graph_t *graph, idx_t *perm, idx_t *match,
          idx_t cnvtxs, size_t nunmatched);
METIS_EXPORT idx_t Match_2HopAny(ctrl_t *ctrl, graph_t *graph, idx_t *perm, idx_t *match,
          idx_t cnvtxs, size_t *r_nunmatched, size_t maxdegree);
METIS_EXPORT idx_t Match_2HopAll(ctrl_t *ctrl, graph_t *graph, idx_t *perm, idx_t *match,
          idx_t cnvtxs, size_t *r_nunmatched, size_t maxdegree);
METIS_EXPORT void PrintCGraphStats(ctrl_t *ctrl, graph_t *graph);
METIS_EXPORT void CreateCoarseGraph(ctrl_t *ctrl, graph_t *graph, idx_t cnvtxs, 
         idx_t *match);
METIS_EXPORT void CreateCoarseGraphNoMask(ctrl_t *ctrl, graph_t *graph, idx_t cnvtxs, 
         idx_t *match);
METIS_EXPORT void CreateCoarseGraphPerm(ctrl_t *ctrl, graph_t *graph, idx_t cnvtxs, 
         idx_t *match, idx_t *perm);
METIS_EXPORT graph_t *SetupCoarseGraph(graph_t *graph, idx_t cnvtxs, idx_t dovsize);
METIS_EXPORT void ReAdjustMemory(ctrl_t *ctrl, graph_t *graph, graph_t *cgraph);



/* compress.c */
METIS_EXPORT graph_t *CompressGraph(ctrl_t *ctrl, idx_t nvtxs, idx_t *xadj, idx_t *adjncy, 
             idx_t *vwgt, idx_t *cptr, idx_t *cind);
METIS_EXPORT graph_t *PruneGraph(ctrl_t *ctrl, idx_t nvtxs, idx_t *xadj, idx_t *adjncy, 
             idx_t *vwgt, idx_t *iperm, real_t factor);


/* contig.c */
METIS_EXPORT idx_t FindPartitionInducedComponents(graph_t *graph, idx_t *where, 
          idx_t *cptr, idx_t *cind);
METIS_EXPORT void ComputeBFSOrdering(ctrl_t *ctrl, graph_t *graph, idx_t *bfsperm);
METIS_EXPORT idx_t IsConnected(graph_t *graph, idx_t report);
METIS_EXPORT idx_t IsConnectedSubdomain(ctrl_t *, graph_t *, idx_t, idx_t);
METIS_EXPORT idx_t FindSepInducedComponents(ctrl_t *, graph_t *, idx_t *, idx_t *);
METIS_EXPORT void EliminateComponents(ctrl_t *ctrl, graph_t *graph);
METIS_EXPORT void MoveGroupContigForCut(ctrl_t *ctrl, graph_t *graph, idx_t to, idx_t gid, 
         idx_t *ptr, idx_t *ind);
METIS_EXPORT void MoveGroupContigForVol(ctrl_t *ctrl, graph_t *graph, idx_t to, idx_t gid,
         idx_t *ptr, idx_t *ind, idx_t *vmarker, idx_t *pmarker,
         idx_t *modind);


/* debug.c */
METIS_EXPORT idx_t ComputeCut(graph_t *graph, idx_t *where);
METIS_EXPORT idx_t ComputeVolume(graph_t *, idx_t *);
METIS_EXPORT idx_t ComputeMaxCut(graph_t *graph, idx_t nparts, idx_t *where);
METIS_EXPORT idx_t CheckBnd(graph_t *);
METIS_EXPORT idx_t CheckBnd2(graph_t *);
METIS_EXPORT idx_t CheckNodeBnd(graph_t *, idx_t);
METIS_EXPORT idx_t CheckRInfo(ctrl_t *ctrl, ckrinfo_t *rinfo);
METIS_EXPORT idx_t CheckNodePartitionParams(graph_t *);
METIS_EXPORT idx_t IsSeparable(graph_t *);
METIS_EXPORT void CheckKWayVolPartitionParams(ctrl_t *ctrl, graph_t *graph);


/* fm.c */
METIS_EXPORT void FM_2WayRefine(ctrl_t *ctrl, graph_t *graph, real_t *ntpwgts, idx_t niter);
METIS_EXPORT void FM_2WayCutRefine(ctrl_t *ctrl, graph_t *graph, real_t *ntpwgts, idx_t niter);
METIS_EXPORT void FM_Mc2WayCutRefine(ctrl_t *ctrl, graph_t *graph, real_t *ntpwgts, idx_t niter);
METIS_EXPORT void SelectQueue(graph_t *graph, real_t *pijbm, real_t *ubfactors, rpq_t **queues, 
         idx_t *from, idx_t *cnum);
METIS_EXPORT void Print2WayRefineStats(ctrl_t *ctrl, graph_t *graph, real_t *ntpwgts, 
         real_t deltabal, idx_t mincutorder);


/* fortran.c */
METIS_EXPORT void Change2CNumbering(idx_t, idx_t *, idx_t *);
METIS_EXPORT void Change2FNumbering(idx_t, idx_t *, idx_t *, idx_t *);
METIS_EXPORT void Change2FNumbering2(idx_t, idx_t *, idx_t *);
METIS_EXPORT void Change2FNumberingOrder(idx_t, idx_t *, idx_t *, idx_t *, idx_t *);
METIS_EXPORT void ChangeMesh2CNumbering(idx_t n, idx_t *ptr, idx_t *ind);
METIS_EXPORT void ChangeMesh2FNumbering(idx_t n, idx_t *ptr, idx_t *ind, idx_t nvtxs,
         idx_t *xadj, idx_t *adjncy);
METIS_EXPORT void ChangeMesh2FNumbering2(idx_t ne, idx_t nn, idx_t *ptr, idx_t *ind,
         idx_t *epart, idx_t *npart);


/* graph.c */
METIS_EXPORT graph_t *SetupGraph(ctrl_t *ctrl, idx_t nvtxs, idx_t ncon, idx_t *xadj, 
             idx_t *adjncy, idx_t *vwgt, idx_t *vsize, idx_t *adjwgt);
METIS_EXPORT void SetupGraph_tvwgt(graph_t *graph);
METIS_EXPORT void SetupGraph_label(graph_t *graph);
METIS_EXPORT graph_t *SetupSplitGraph(graph_t *graph, idx_t snvtxs, idx_t snedges);
METIS_EXPORT graph_t *CreateGraph(void);
METIS_EXPORT void InitGraph(graph_t *graph);
METIS_EXPORT void FreeRData(graph_t *graph);
METIS_EXPORT void FreeGraph(graph_t **graph);


/* initpart.c */
METIS_EXPORT void Init2WayPartition(ctrl_t *ctrl, graph_t *graph, real_t *ntpwgts, idx_t niparts);
METIS_EXPORT void InitSeparator(ctrl_t *ctrl, graph_t *graph, idx_t niparts);
METIS_EXPORT void RandomBisection(ctrl_t *ctrl, graph_t *graph, real_t *ntpwgts, idx_t niparts);
METIS_EXPORT void GrowBisection(ctrl_t *ctrl, graph_t *graph, real_t *ntpwgts, idx_t niparts);
METIS_EXPORT void McRandomBisection(ctrl_t *ctrl, graph_t *graph, real_t *ntpwgts, idx_t niparts);
METIS_EXPORT void McGrowBisection(ctrl_t *ctrl, graph_t *graph, real_t *ntpwgts, idx_t niparts);
METIS_EXPORT void GrowBisectionNode(ctrl_t *ctrl, graph_t *graph, real_t *ntpwgts, idx_t niparts);
METIS_EXPORT void GrowBisectionNode2(ctrl_t *ctrl, graph_t *graph, real_t *ntpwgts, idx_t niparts);


/* kmetis.c */
METIS_EXPORT idx_t MlevelKWayPartitioning(ctrl_t *ctrl, graph_t *graph, idx_t *part);
METIS_EXPORT void InitKWayPartitioning(ctrl_t *ctrl, graph_t *graph);


/* kwayfm.c */
METIS_EXPORT void Greedy_KWayOptimize(ctrl_t *ctrl, graph_t *graph, idx_t niter, 
         real_t ffactor, idx_t omode);
METIS_EXPORT void Greedy_KWayCutOptimize(ctrl_t *ctrl, graph_t *graph, idx_t niter, 
         real_t ffactor, idx_t omode);
METIS_EXPORT void Greedy_KWayVolOptimize(ctrl_t *ctrl, graph_t *graph, idx_t niter, 
         real_t ffactor, idx_t omode);
METIS_EXPORT void Greedy_McKWayCutOptimize(ctrl_t *ctrl, graph_t *graph, idx_t niter, 
         real_t ffactor, idx_t omode);
METIS_EXPORT void Greedy_McKWayVolOptimize(ctrl_t *ctrl, graph_t *graph, idx_t niter, 
         real_t ffactor, idx_t omode);
METIS_EXPORT idx_t IsArticulationNode(idx_t i, idx_t *xadj, idx_t *adjncy, idx_t *where,
          idx_t *bfslvl, idx_t *bfsind, idx_t *bfsmrk);
METIS_EXPORT void KWayVolUpdate(ctrl_t *ctrl, graph_t *graph, idx_t v, idx_t from,
         idx_t to, ipq_t *queue, idx_t *vstatus, idx_t *r_nupd, idx_t *updptr,
         idx_t *updind, idx_t bndtype, idx_t *vmarker, idx_t *pmarker,
         idx_t *modind);


/* kwayrefine.c */
METIS_EXPORT void RefineKWay(ctrl_t *ctrl, graph_t *orggraph, graph_t *graph);
METIS_EXPORT void AllocateKWayPartitionMemory(ctrl_t *ctrl, graph_t *graph);
METIS_EXPORT void ComputeKWayPartitionParams(ctrl_t *ctrl, graph_t *graph);
METIS_EXPORT void ProjectKWayPartition(ctrl_t *ctrl, graph_t *graph);
METIS_EXPORT void ComputeKWayBoundary(ctrl_t *ctrl, graph_t *graph, idx_t bndtype);
METIS_EXPORT void ComputeKWayVolGains(ctrl_t *ctrl, graph_t *graph);
METIS_EXPORT int IsBalanced(ctrl_t *ctrl, graph_t *graph, real_t ffactor);


/* mcutil.c */
METIS_EXPORT int rvecle(idx_t n, real_t *x, real_t *y);
METIS_EXPORT int rvecge(idx_t n, real_t *x, real_t *y);
METIS_EXPORT int rvecsumle(idx_t n, real_t *x1, real_t *x2, real_t *y);
METIS_EXPORT real_t rvecmaxdiff(idx_t n, real_t *x, real_t *y);
METIS_EXPORT int ivecle(idx_t n, idx_t *x, idx_t *z);
METIS_EXPORT int ivecge(idx_t n, idx_t *x, idx_t *z);
METIS_EXPORT int ivecaxpylez(idx_t n, idx_t a, idx_t *x, idx_t *y, idx_t *z);
METIS_EXPORT int ivecaxpygez(idx_t n, idx_t a, idx_t *x, idx_t *y, idx_t *z);
METIS_EXPORT int BetterVBalance(idx_t ncon, real_t *itvwgt, idx_t *v_vwgt, idx_t *u1_vwgt,
            idx_t *u2_vwgt);
METIS_EXPORT int BetterBalance2Way(idx_t n, real_t *x, real_t *y);
METIS_EXPORT int BetterBalanceKWay(idx_t ncon, idx_t *vwgt, real_t *itvwgt, idx_t a1,
        idx_t *pt1, real_t *bm1, idx_t a2, idx_t *pt2, real_t *bm2);
METIS_EXPORT real_t ComputeLoadImbalance(graph_t *graph, idx_t nparts, real_t *pijbm);
METIS_EXPORT real_t ComputeLoadImbalanceDiff(graph_t *graph, idx_t nparts, real_t *pijbm, 
           real_t *ubvec);
METIS_EXPORT real_t ComputeLoadImbalanceDiffVec(graph_t *graph, idx_t nparts, real_t *pijbm, 
         real_t *ubfactors, real_t *diffvec);
METIS_EXPORT void ComputeLoadImbalanceVec(graph_t *graph, idx_t nparts, real_t *pijbm,
             real_t *lbvec);


/* mesh.c */
METIS_EXPORT void CreateGraphDual(idx_t ne, idx_t nn, idx_t *eptr, idx_t *eind, idx_t ncommon,
          idx_t **r_xadj, idx_t **r_adjncy);
METIS_EXPORT idx_t FindCommonElements(idx_t qid, idx_t elen, idx_t *eind, idx_t *nptr,
          idx_t *nind, idx_t *eptr, idx_t ncommon, idx_t *marker, idx_t *nbrs);
METIS_EXPORT void CreateGraphNodal(idx_t ne, idx_t nn, idx_t *eptr, idx_t *eind, idx_t **r_xadj, 
          idx_t **r_adjncy);
METIS_EXPORT idx_t FindCommonNodes(idx_t qid, idx_t nelmnts, idx_t *elmntids, idx_t *eptr,
          idx_t *eind, idx_t *marker, idx_t *nbrs);
METIS_EXPORT mesh_t *CreateMesh(void);
METIS_EXPORT void InitMesh(mesh_t *mesh);  
METIS_EXPORT void FreeMesh(mesh_t **mesh);


/* meshpart.c */
METIS_EXPORT void InduceRowPartFromColumnPart(idx_t nrows, idx_t *rowptr, idx_t *rowind,
         idx_t *rpart, idx_t *cpart, idx_t nparts, real_t *tpwgts);


/* minconn.c */
METIS_EXPORT void ComputeSubDomainGraph(ctrl_t *ctrl, graph_t *graph);
METIS_EXPORT void UpdateEdgeSubDomainGraph(ctrl_t *ctrl, idx_t u, idx_t v, idx_t ewgt, 
         idx_t *r_maxndoms);
METIS_EXPORT void PrintSubDomainGraph(graph_t *graph, idx_t nparts, idx_t *where);
METIS_EXPORT void EliminateSubDomainEdges(ctrl_t *ctrl, graph_t *graph);
METIS_EXPORT void MoveGroupMinConnForCut(ctrl_t *ctrl, graph_t *graph, idx_t to, idx_t nind, 
         idx_t *ind);
METIS_EXPORT void MoveGroupMinConnForVol(ctrl_t *ctrl, graph_t *graph, idx_t to, idx_t nind, 
         idx_t *ind, idx_t *vmarker, idx_t *pmarker, idx_t *modind);


/* mincover.o */
METIS_EXPORT void MinCover(idx_t *, idx_t *, idx_t, idx_t, idx_t *, idx_t *);
METIS_EXPORT idx_t MinCover_Augment(idx_t *, idx_t *, idx_t, idx_t *, idx_t *, idx_t *, idx_t);
METIS_EXPORT void MinCover_Decompose(idx_t *, idx_t *, idx_t, idx_t, idx_t *, idx_t *, idx_t *);
METIS_EXPORT void MinCover_ColDFS(idx_t *, idx_t *, idx_t, idx_t *, idx_t *, idx_t);
METIS_EXPORT void MinCover_RowDFS(idx_t *, idx_t *, idx_t, idx_t *, idx_t *, idx_t);


/* mmd.c */
METIS_EXPORT void genmmd(idx_t, idx_t *, idx_t *, idx_t *, idx_t *, idx_t , idx_t *, idx_t *, idx_t *, idx_t *, idx_t, idx_t *);
METIS_EXPORT void mmdelm(idx_t, idx_t *xadj, idx_t *, idx_t *, idx_t *, idx_t *, idx_t *, idx_t *, idx_t *, idx_t, idx_t);
METIS_EXPORT idx_t mmdint(idx_t, idx_t *xadj, idx_t *, idx_t *, idx_t *, idx_t *, idx_t *, idx_t *, idx_t *);
METIS_EXPORT void mmdnum(idx_t, idx_t *, idx_t *, idx_t *);
METIS_EXPORT void mmdupd(idx_t, idx_t, idx_t *, idx_t *, idx_t, idx_t *, idx_t *, idx_t *, idx_t *, idx_t *, idx_t *, idx_t *, idx_t, idx_t *tag);


/* ometis.c */
METIS_EXPORT void MlevelNestedDissection(ctrl_t *ctrl, graph_t *graph, idx_t *order,
         idx_t lastvtx);
METIS_EXPORT void MlevelNestedDissectionCC(ctrl_t *ctrl, graph_t *graph, idx_t *order,
         idx_t lastvtx);
METIS_EXPORT void MlevelNodeBisectionMultiple(ctrl_t *ctrl, graph_t *graph);
METIS_EXPORT void MlevelNodeBisectionL2(ctrl_t *ctrl, graph_t *graph, idx_t niparts);
METIS_EXPORT void MlevelNodeBisectionL1(ctrl_t *ctrl, graph_t *graph, idx_t niparts);
METIS_EXPORT void SplitGraphOrder(ctrl_t *ctrl, graph_t *graph, graph_t **r_lgraph, 
         graph_t **r_rgraph);
METIS_EXPORT graph_t **SplitGraphOrderCC(ctrl_t *ctrl, graph_t *graph, idx_t ncmps,
              idx_t *cptr, idx_t *cind);
METIS_EXPORT void MMDOrder(ctrl_t *ctrl, graph_t *graph, idx_t *order, idx_t lastvtx);


/* options.c */
METIS_EXPORT ctrl_t *SetupCtrl(moptype_et optype, idx_t *options, idx_t ncon, idx_t nparts, 
            real_t *tpwgts, real_t *ubvec);
METIS_EXPORT void SetupKWayBalMultipliers(ctrl_t *ctrl, graph_t *graph);
METIS_EXPORT void Setup2WayBalMultipliers(ctrl_t *ctrl, graph_t *graph, real_t *tpwgts);
METIS_EXPORT void PrintCtrl(ctrl_t *ctrl);
METIS_EXPORT int CheckParams(ctrl_t *ctrl);
METIS_EXPORT void FreeCtrl(ctrl_t **r_ctrl);


/* parmetis.c */
METIS_EXPORT void MlevelNestedDissectionP(ctrl_t *ctrl, graph_t *graph, idx_t *order,
         idx_t lastvtx, idx_t npes, idx_t cpos, idx_t *sizes);
METIS_EXPORT void FM_2WayNodeRefine1SidedP(ctrl_t *ctrl, graph_t *graph, idx_t *hmarker, 
         real_t ubfactor, idx_t npasses);
METIS_EXPORT void FM_2WayNodeRefine2SidedP(ctrl_t *ctrl, graph_t *graph, idx_t *hmarker, 
         real_t ubfactor, idx_t npasses);


/* pmetis.c */
METIS_EXPORT idx_t MlevelRecursiveBisection(ctrl_t *ctrl, graph_t *graph, idx_t nparts, 
          idx_t *part, real_t *tpwgts, idx_t fpart);
METIS_EXPORT idx_t MultilevelBisect(ctrl_t *ctrl, graph_t *graph, real_t *tpwgts);
METIS_EXPORT void SplitGraphPart(ctrl_t *ctrl, graph_t *graph, graph_t **r_lgraph, graph_t **r_rgraph);


/* refine.c */
METIS_EXPORT void Refine2Way(ctrl_t *ctrl, graph_t *orggraph, graph_t *graph, real_t *rtpwgts);
METIS_EXPORT void Allocate2WayPartitionMemory(ctrl_t *ctrl, graph_t *graph);
METIS_EXPORT void Compute2WayPartitionParams(ctrl_t *ctrl, graph_t *graph);
METIS_EXPORT void Project2WayPartition(ctrl_t *ctrl, graph_t *graph);


/* separator.c */
METIS_EXPORT void ConstructSeparator(ctrl_t *ctrl, graph_t *graph);
METIS_EXPORT void ConstructMinCoverSeparator(ctrl_t *ctrl, graph_t *graph);


/* sfm.c */
METIS_EXPORT void FM_2WayNodeRefine2Sided(ctrl_t *ctrl, graph_t *graph, idx_t niter);
METIS_EXPORT void FM_2WayNodeRefine1Sided(ctrl_t *ctrl, graph_t *graph, idx_t niter);
METIS_EXPORT void FM_2WayNodeBalance(ctrl_t *ctrl, graph_t *graph);


/* srefine.c */
METIS_EXPORT void Refine2WayNode(ctrl_t *ctrl, graph_t *orggraph, graph_t *graph);
METIS_EXPORT void Allocate2WayNodePartitionMemory(ctrl_t *ctrl, graph_t *graph);
METIS_EXPORT void Compute2WayNodePartitionParams(ctrl_t *ctrl, graph_t *graph);
METIS_EXPORT void Project2WayNodePartition(ctrl_t *ctrl, graph_t *graph);


/* stat.c */
METIS_EXPORT void ComputePartitionInfoBipartite(graph_t *, idx_t, idx_t *);
METIS_EXPORT void ComputePartitionBalance(graph_t *, idx_t, idx_t *, real_t *);
METIS_EXPORT real_t ComputeElementBalance(idx_t, idx_t, idx_t *);


/* timing.c */
METIS_EXPORT void InitTimers(ctrl_t *);
METIS_EXPORT void PrintTimers(ctrl_t *);

/* util.c */
METIS_EXPORT idx_t iargmax_strd(size_t, idx_t *, idx_t);
METIS_EXPORT idx_t iargmax_nrm(size_t n, idx_t *x, real_t *y);
METIS_EXPORT idx_t iargmax2_nrm(size_t n, idx_t *x, real_t *y);
METIS_EXPORT idx_t rargmax2(size_t, real_t *);
METIS_EXPORT void InitRandom(idx_t);
METIS_EXPORT int metis_rcode(int sigrval);



/* wspace.c */
METIS_EXPORT void AllocateWorkSpace(ctrl_t *ctrl, graph_t *graph);
METIS_EXPORT void AllocateRefinementWorkSpace(ctrl_t *ctrl, idx_t nbrpoolsize);
METIS_EXPORT void FreeWorkSpace(ctrl_t *ctrl);
METIS_EXPORT void *wspacemalloc(ctrl_t *ctrl, size_t nbytes);
METIS_EXPORT void wspacepush(ctrl_t *ctrl);
METIS_EXPORT void wspacepop(ctrl_t *ctrl);
METIS_EXPORT idx_t *iwspacemalloc(ctrl_t *, idx_t);
METIS_EXPORT real_t *rwspacemalloc(ctrl_t *, idx_t);
METIS_EXPORT ikv_t *ikvwspacemalloc(ctrl_t *, idx_t);
METIS_EXPORT void cnbrpoolReset(ctrl_t *ctrl);
METIS_EXPORT idx_t cnbrpoolGetNext(ctrl_t *ctrl, idx_t nnbrs);
METIS_EXPORT void vnbrpoolReset(ctrl_t *ctrl);
METIS_EXPORT idx_t vnbrpoolGetNext(ctrl_t *ctrl, idx_t nnbrs);


#endif
