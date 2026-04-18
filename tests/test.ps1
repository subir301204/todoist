$exe = Join-Path $PSScriptRoot "..\todoist.exe"

# -----------------------
# Test 1: Basic argument count
# -----------------------
$output1 = & $exe
if ($output1 -match "ERROR: Wrong argument count...") {
    Write-Host "PASS test 1 - Basic argument count"
}
else {
    Write-Host "FAIL test 1 - Basic argument count"
}
