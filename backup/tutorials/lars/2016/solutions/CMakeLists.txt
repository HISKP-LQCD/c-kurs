# Copyright © 2017 Martin Ueding <dev@martin-ueding.de>

cmake_minimum_required(VERSION 2.8.11)

project(loesungen C)

add_definitions(-Wall -Wpedantic --std=c99)

add_executable(cos cos.c)
add_executable(ggt ggt.c)
add_executable(heron heron.c)
add_executable(primzahlen primzahlen.c)
add_executable(sgn-betrag-wurzel sgn-betrag-wurzel.c)
add_executable(zeta-2 zeta-2.c)
add_executable(zeta zeta.c)
target_link_libraries(zeta m)
