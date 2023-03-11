workspace "Series"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "Series"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "Series"