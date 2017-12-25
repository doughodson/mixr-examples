
# ---------------------------------------------------------------------
# Setup environment variables for MIXR and examples
# (Edit as required)
# ---------------------------------------------------------------------

# ---
# MIXR root
# ---
MIXR_ROOT=$PWD/../mixr
export MIXR_ROOT

# ---
# MIXR examples root
# ---
MIXR_EXAMPLES_ROOT=$PWD
export MIXR_EXAMPLES_ROOT

# ---
# MIXR examples library path
# ---
MIXR_EXAMPLES_LIB_PATH=$PWD/lib
export MIXR_EXAMPLES_LIB_PATH

# ---
# MIXR data
# ---
MIXR_DATA_ROOT=$PWD/../mixr-data
export MIXR_DATA_ROOT

# ---
# MIXR 3rd party (e.g. cigi, JSBSim) root
# ---
MIXR_3RD_PARTY_ROOT=$PWD/../mixr-3rdparty
export MIXR_3RD_PARTY_ROOT

# ---
# Update the loader library path with our 3rd party library path
# ---
LD_LIBRARY_PATH=$MIXR_3RD_PARTY_ROOT/lib:${LD_LIBRARY_PATH}
export LD_LIBRARY_PATH

# ---
# Update path to search for binaries in our 3rd party library path
# ---
PATH=$MIXR_3RD_PARTY_ROOT/bin:$PATH
export PATH

