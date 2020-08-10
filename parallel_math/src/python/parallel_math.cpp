//
// Created by Santiago Hurtado on 10.11.19.
//

#define BOOST_PYTHON_STATIC_LIB

#include "parallel/Vectors.h"
#include "parallel/NaturalNumbers.h"
#include <boost/python.hpp>

#include <vector>
#define BOOST_PYTHON_STATIC_LIB

#include <boost/python.hpp>

BOOST_PYTHON_MODULE (parallel_math) {
        boost::python::class_<parallel::NaturalNumbers>("NaturalNumbers")
                .def("size",&parallel::NaturalNumbers::size)
                .def("get",&parallel::NaturalNumbers::get)
                .def("calculate_sum_primes",&parallel::NaturalNumbers::calculate_sum_primes)
                .def("results",boost::python::range(&parallel::NaturalNumbers::begin,
                                                    &parallel::NaturalNumbers::end));

        boost::python::class_<parallel::Vectors>("Vectors")
                .def("size",&parallel::Vectors::size)
                .def("get",&parallel::Vectors::get)
                .def("sum",&parallel::Vectors::sum_size)
                .def("results",boost::python::range(&parallel::Vectors::begin,
                                                    &parallel::Vectors::end));
}