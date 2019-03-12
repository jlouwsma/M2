#include "NCGroebner.hpp"

void NCGroebner::compute(int maxdeg)
{
  // TODO
}

const NCGroebner::ConstPolyList* NCGroebner::currentValue()
{
  // TODO
  return &mInput;
}

#if 0
class NCPolyHeap
{
  using Poly = PolynomialAlgebra::Poly;
  const PolynomialAlgebra& mRing;  // Our elements will be vectors in here
  Poly mHeap[GEOHEAP_SIZE];
  Poly::Iterator mLead[GEOHEAP_SIZE];
  int mTop; // largest index into mHeap which has a polynomial in it.

  bool leadTermComputed;
  ring_elem mLeadCoefficient;
  ConstMonomial mLeadMonomial;
 public:
  NCPolyHeap(const PolynomialAlgebra& F);
  ~NCPolyHeap();

  void add(const Poly& f);

  void subtractMultiple(ring_elem coeff, Word& left, const Poly* g, Word& right);

  bool computeLeadTerm();
  ring_elem leadTermCoefficient();
  ConstMonomial leadTermMonomial();
  
    Poly value();  // Returns the linearized value, and resets the NCPolyHeap.

  ring_elem getValue();
  void add(ring_elem f1);
  
  const Poly& debug_list(int i) const
  {
    return mHeap[i];
  }  // DO NOT USE, except for debugging purposes!
};

class PolyWithPosition
{
public:
  PolyWithPosition(std::unique_ptr<Poly>(f));
private:
  Poly* mPoly;
  Poly::iterator mLead;
};
#endif

auto NCGroebner::twoSidedReduction(const PolynomialAlgebra* A,
                                   const Poly* reducee,
                                   const ConstPolyList& reducers,
                                   const WordTable& W) -> const Poly*
{
  Poly* remainder = new Poly;
  // pair will be (i,j) where the ith word in wordtable appears in word in position j
  std::pair<int,int> subwordPos; 
  const int* lmPtr;
  std::vector<int> leftMonom, rightMonom;
  Poly* result = new Poly;
#if 0
  while (reducee != 0)
    {
      // Find (left, right, index) s.t. left*reducers[index]*right == leadMonomial(reducee).
      ConstMonomial reduceeLM(f->cbegin().monom().begin()+2,f->cbegin().monom().end());
      if (W.subword(reduceeLM,subwordPos))
        {
          // If one, subtract reducee -= coef * left*reducers[index]*right
          // build left monomial
          leftMonom.push_back(j + 2);
          leftMonom.push_back(j);
          leftMonom.insert(leftMonom.end(),
                           f->cbegin().monom().begin()+2,
                           f->cbegin().monom().begin()+2+j);
          // build right monomial
          rightMonom.push_back(reduceeLM.size() - W[subwordPos.first].size() - subwordPos.second + 2);
          rightMonom.push_back(reduceeLM.size() - W[subwordPos.first].size() - subwordPos.second);
          rightMonom.insert(rightMonom.end(),
                            f->cbegin().monom().begin+W[subwordPos.first].size()+subwordPos.second+2,
                            f->cbegin().monom.end());
          
        }
      else
        {
          // If none, copy that term to the remainder.          
        }
    }
#endif  
  return remainder;
}

auto NCGroebner::twoSidedReduction(const PolynomialAlgebra* A,
                                   const ConstPolyList& reducees,
                                   const ConstPolyList& reducers) -> ConstPolyList
{
  WordTable W;
  // Build the word table for the reduction
  for (auto& f : reducers)
    {
      auto i = f->cbegin();
      W.insert(ConstMonomial(i.monom().begin()+2, i.monom().end()));
    }
  ConstPolyList result;
  for (auto i = reducees.cbegin(); i != reducees.cend(); ++i)
    result.push_back(twoSidedReduction(A, *i, reducers, W));
  return result;
}


// Local Variables:
// compile-command: "make -C $M2BUILDDIR/Macaulay2/e  "
// indent-tabs-mode: nil
// End:
