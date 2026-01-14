#!/bin/bash
# clean.sh - 保留指定后缀文件，删除其他文件
# 可修改保留后缀列表

# 定义要保留的文件后缀（按需添加）
KEEP_SUFFIXES=(".cpp" ".md" ".sh" ".c")

for file in *; do
    if [ -f "$file" ]; then
        # 标记是否为保留文件
        keep=0
        for suffix in "${KEEP_SUFFIXES[@]}"; do
            if [[ "$file" == *"$suffix" ]]; then
                keep=1
                break
            fi
        done
        # 非保留文件则删除
        if [ $keep -eq 0 ]; then
            rm -f "$file"
            echo "Deleted: $file"
        fi
    fi
done

echo "Cleanup done!"

