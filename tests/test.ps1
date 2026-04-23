$exe = Join-Path $PSScriptRoot "..\todo.exe"

# -----------------------
# Test 1: Basic no flag
# -----------------------
$output1 = & $exe 2>&1
if ($output1 -match "ERROR: We need an argument to perform any operation.") {
    Write-Host "PASS test 1 - Basic no flag"
}
else {
    Write-Host "FAIL test 1 - Basic no flag"
    Write-Host "Output was: [$output1]"
}

# -----------------------
# Test 2: Basic wrong flag
# -----------------------
$output2 = & $exe -f 2>&1
if ($output2 -match "ERROR") {
    Write-Host "PASS test 2 - Basic wrong flag"
} else {
    Write-Host "FAIL test 2 - Basic wrong flag"
    Write-Host "Output was: [$output2]"
}

# -----------------------
# Test 3: create task flag
# -----------------------
$output3 = @"
1
Buy milk
Some description
"@ | & $exe -c 2>&1
if ($output3 -match "Task added successfully!") {
    Write-Host "PASS test 3 - create task flag"
} else {
    Write-Host "FAIL test 3 - create task flag"
    Write-Host "Output was: [$output3]"
}

# -----------------------
# Test 4 : mark as complete flag
# -----------------------
$output4 =@"
1
"@ | & $exe -x 2>&1
if ($output4 -match "Task marked as completed.") {
    Write-Host "PASS test 4 - mark as complete flag"
} else {
    Write-Host "FAIL test 4 - mark as complete flag"
    Write-Host "Output was: [$output4]"
}

# -----------------------
# Test 5 : delete tasks flag
# -----------------------
$output5 = @"
1
"@ | & $exe -d 2>&1
if ($output5 -match "Task deleted successfully.") {
    Write-Host "PASS test 5 - delete tasks flag"
} else {
    Write-Host "FAIL test 5 - delete tasks flag"
    Write-Host "Output was: [$output5]"
}

# -----------------------
# Test 6: help flag
# -----------------------
$output6 = & $exe -h 2>&1
if ($output6 -match "USAGE: todo <necessary flags>") {
    Write-Host "PASS test 6 - help flag"
} else {
    Write-Host "PASS test 6 - help flag"
    Write-Host "Output was: [$output6]"
}
