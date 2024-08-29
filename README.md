# xeyday.math
C++17 constexpr, SIMD-aware math library for games

# Ideas/roadmap
- [ ] Types
  - [ ] Vector 2/3/4
  - [ ] Matrix up to 4x4
  - [ ] Quaternion
  - [ ] Point, rectangle, circle
  - [ ] Box, sphere, cylinder
  - [ ] Plane
  - [ ] OBB, AABB
  - [ ] Frustum
- [ ] Properties (priority sorted)
  - [ ] Generated
    - [ ] Configurable like [GLAD](https://github.com/Dav1dde/glad) with options:
      - [ ] Each scalar C++ type as an option (int/short/unsigned int/float/double/long double/etc)
      - [ ] SIMD
        - [ ] Run-time SIMD evaluation
      - [ ] Compile-time evaluation (constexpr support)
      - [ ] Precise/approximated math
        - [ ] Precise math should [IEEE-754](https://en.wikipedia.org/wiki/IEEE_754) be compliant
        - [ ] Control precision/approximation control via tags (that are arguments to functions)?
      - [ ] Swizzles (like in hlsl/glsl)
  - [ ] Compatible with [C++20/C++23/C++26 standard library improvements](https://en.cppreference.com/w/cpp/numeric)
  - [ ] HLSL/GLSL compatible
    - [ ] Memory layout compatible
  - [ ] C support
    - [ ] At least memory layout compatible, use same types for C and C++ if possible.

## Libraries to look at to get inspiration and ideas
- https://github.com/redorav/hlslpp
- https://github.com/kthohr/gcem
- https://github.com/Morwenn/static_math
- https://github.com/nfrechette/rtm
- https://github.com/valentingalea/vml
- https://github.com/gwiazdorrr/CxxSwizzle
- https://github.com/yandex/fastops
- https://github.com/google/mathfu
- https://github.com/davideberly/GeometricTools
- https://github.com/jtsiomb/gph-math
- https://github.com/dangmoody/HLML
- https://github.com/demianmnave/CML
- https://github.com/andersx/libsimdmath
- https://github.com/ebassi/graphene

### SIMD
- https://github.com/google/highway
- https://github.com/simd-everywhere/simde
- https://github.com/xtensor-stack/xsimd
- https://github.com/p12tic/libsimdpp
- https://github.com/jfalcou/eve
- https://github.com/gnuradio/volk
- https://github.com/jeffamstutz/tsimd

### Generators
- https://github.com/pantor/inja
- https://github.com/pallets/jinja
