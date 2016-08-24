void __ESBMC_assert(_Bool x, char *msg);
void __ESBMC_assume(_Bool x);
void __ESBMC_atomic_begin(void);
void __ESBMC_atomic_end(void);
void __ESBMC_yield(void);
void __ESBMC_switch_to(unsigned int tid);

int __ESBMC_abs(int);
long int __ESBMC_labs(long int);
long long int __ESBMC_llabs(long long int);
double __ESBMC_fabs(double);
long double __ESBMC_fabsl(long double);
float __ESBMC_fabsf(float);

_Bool __ESBMC_isfinite(double f);
_Bool __ESBMC_isinf(double f);
_Bool __ESBMC_isnormal(double f);
_Bool __ESBMC_sign(double f);
_Bool __ESBMC_isnanf(float f);
_Bool __ESBMC_isnand(double f);
_Bool __ESBMC_isnanld(long double f);
_Bool __ESBMC_isfinitef(float f);
_Bool __ESBMC_isfinited(double f);
_Bool __ESBMC_isfiniteld(long double f);
_Bool __ESBMC_isinff(float f);
_Bool __ESBMC_isinfd(double f);
_Bool __ESBMC_isinfld(long double f);
_Bool __ESBMC_isnormalf(float f);
_Bool __ESBMC_isnormald(double f);
_Bool __ESBMC_isnormalld(long double f);
_Bool __ESBMC_signf(float f);
_Bool __ESBMC_signd(double f);
_Bool __ESBMC_signld(long double f);
double __ESBMC_inf(void);
float __ESBMC_inff(void);
long double __ESBMC_infl(void);

typedef void *(*__ESBMC_thread_start_func_type)(void *);

void __ESBMC_terminate_thread(void);
