#!/usr/bin/env bash
# =============================================================================
#  gen_pack.sh -- Build a CMSIS Pack archive (.pack) for the NTiny SDK.
#
#  A CMSIS Pack is just a renamed ZIP containing the PDSC at the top level,
#  the Device/, Drivers/, Utilities/, CMSIS/, Examples/ directories, the
#  README, and the LICENSE. IDEs (Keil µVision, IAR EWARM, STM32CubeIDE,
#  Eclipse with the CMSIS pack manager, VS Code Cortex-Debug, etc.) consume
#  the pack to install the SDK and surface its components, drivers and
#  examples in the project wizard.
#
#  Usage:  ./gen_pack.sh [output-dir]
# =============================================================================

set -euo pipefail

PACK_NAME="NTiny.NTinySDK"
PDSC="${PACK_NAME}.pdsc"

if [[ ! -f "${PDSC}" ]]; then
    echo "error: ${PDSC} not found at $(pwd). Run from the SDK root." >&2
    exit 1
fi

# Extract the version number from the most recent <release> tag in the PDSC.
VERSION=$(grep -oE '<release version="[0-9]+\.[0-9]+\.[0-9]+"' "${PDSC}" \
          | head -1 | grep -oE '[0-9]+\.[0-9]+\.[0-9]+')

if [[ -z "${VERSION}" ]]; then
    echo "error: could not parse version from ${PDSC}" >&2
    exit 1
fi

OUT_DIR="${1:-.}"
PACK_FILE="${OUT_DIR}/${PACK_NAME}.${VERSION}.pack"

# Files and directories to include. Anything else (build output, .git, .vscode,
# the App/ Eclipse template, etc.) is skipped.
INCLUDES=(
    "${PDSC}"
    "LICENSE"
    "README.md"
    "Device"
    "Drivers"
    "Utilities"
    "CMSIS"
    "Examples"
    "Libraries"
)

echo "Packing CMSIS Pack ${PACK_NAME} v${VERSION} -> ${PACK_FILE}"

# Use zip with -r and exclude noise.
rm -f "${PACK_FILE}"
zip -r "${PACK_FILE}" "${INCLUDES[@]}" \
    -x '*/.git/*' '*/Debug/*' '*/Release/*' '*/build/*' \
       '*.o' '*.d' '*.elf' '*.bin' '*.hex' '*.map' \
       '*/.DS_Store' '*/Thumbs.db'

echo "Created: ${PACK_FILE}"
echo "Verify the archive contents with:  unzip -l ${PACK_FILE}"
