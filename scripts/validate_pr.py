#!/usr/bin/env python3
import os
import sys

# Minimal non-failing PR validation placeholder
# Prints environment variables provided by the workflow so we can inspect them in the job logs.

def main():
    print("validate_pr: placeholder — environment:")
    print("PR_TITLE =", os.getenv("PR_TITLE"))
    print("PR_BODY  =", os.getenv("PR_BODY"))
    print("BASE_SHA =", os.getenv("BASE_SHA"))
    print("HEAD_SHA =", os.getenv("HEAD_SHA"))
    # Add a simple hint to be visible in logs
    print("validate_pr: placeholder script completed successfully.")
    return 0

if __name__ == '__main__':
    sys.exit(main())
