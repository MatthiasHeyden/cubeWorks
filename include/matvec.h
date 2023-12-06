int cpyVec(t_vec a,t_vec *b);
int cpyMat(t_mat a,t_mat *b);
int linkPBC(t_vec a,t_vec b,float box,t_vec *c);
int vecNorm(t_vec a,double *d);
int vecNormSq(t_vec a,double *dSq);
int vecDot(t_vec a,t_vec b,double *res);
int distPBC(t_vec a,t_vec b,float box,double *d);
int matvec(t_mat a,t_vec b,t_vec *c);
int matTvec(t_mat a,t_vec b,t_vec *c);
int matmat(t_mat a,t_mat b,t_mat *c);
int matTmat(t_mat a,t_mat b,t_mat *c);
int randUnitVec(t_vec *a);
int rotZ(double angle,t_mat *rz);
int rotX(double angle,t_mat *rx);
int rotAny(double angle,t_vec axis,t_mat *r);
int scaleVec(double s,t_vec *v);
int addVec(t_vec a,t_vec b,t_vec *c);
int addVec3(t_vec a,t_vec b1,t_vec b2,t_vec b3,t_vec *c);
int addVec3scale(t_vec a,double scale,t_vec b1,t_vec b2,t_vec b3,t_vec *c);
int subVec3(t_vec a,t_vec b1,t_vec b2,t_vec b3,t_vec *c);
int subVec3scale(t_vec a,double scale,t_vec b1,t_vec b2,t_vec b3,t_vec *c);
int subVec(t_vec a,t_vec b,t_vec *c);
int subVec3(t_vec a,t_vec b,t_vec c t_vec d,t_vec *res);
int crossCompleteMat(t_mat *a);
int getMolCrd(t_mat rot,t_vec trans,t_mol *mol);
