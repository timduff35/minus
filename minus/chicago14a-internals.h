#ifndef chicago14a_internals_h
#define chicago14a_internals_h
// TODO: rename to io

namespace MiNuS {

template <typename F>
struct minus_io<chicago14a, F> : public minus_io_14a<chicago14a, F> {
  // template specialization defined in problem-internals.h
  typedef problem_parameters<chicago14a> pp;
  typedef minus_core<chicago14a, F> M;
  typedef minus_io_common<F> io;
  // shortcuts to the problem parameters
  static constexpr unsigned nviews  = pp::nviews;
  static constexpr unsigned npoints = pp::npoints;
  // Input ---------------------------------------------------------------------
  static void gammify(C<F> * __restrict__ params/*[ chicago: M::nparams]*/);
  // Chicago-specific input 
  static void point_tangents2params(const F p[pp::nviews][pp::npoints][io::ncoords2d], const F tgt[pp::nviews][pp::npoints][io::ncoords2d], unsigned id_tgt0, unsigned id_tgt1, C<F> * __restrict__ params/*[static 2*M::nparams]*/);
  static void point_tangents2params_img(const F p[pp::nviews][pp::npoints][io::ncoords2d], const F tgt[pp::nviews][pp::npoints][io::ncoords2d], unsigned id_tgt0, unsigned id_tgt1, const F K[/*3 or 2*/][io::ncoords2d_h], C<F> * __restrict__ params/*[static 2*M::nparams]*/);
  // this function is the same for all problems
  static void get_params_start_target(F plines[/*15 for chicago*/][io::ncoords2d_h], C<F> * __restrict__ params/*[static 2*M::nparams]*/);
  static void point_tangents2lines(const F p[pp::nviews][pp::npoints][io::ncoords2d], const F tgt[pp::nviews][pp::npoints][io::ncoords2d], unsigned id_tgt0, unsigned id_tgt1, F plines[pp::nvislines][io::ncoords2d_h]);
  static void lines2params(const F plines[pp::nvislines][io::ncoords2d_h], C<F> * __restrict__ params/*[static M::n//params]*/);
  // Output --------------------------------------------------------------------
  static bool has_valid_solutions(const typename M::solution solutions[M::nsols]);
};

} // namespace minus

#endif //chicago14a_internals_h
