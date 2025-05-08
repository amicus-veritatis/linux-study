#/bin/sh
file="${1:--}"
[ "$file" = "-" ] && file="/dev/stdin"
if [ "$file" = "/dev/stdin" ]; then
    tmpfile=$(mktemp) || { echo "Error creating temporary file" >&2; exit 1; }
    cat > "$tmpfile"
    file=$tmpfile
else
    echo "Comparing files using '$file'"
fi

for f in *; do
    case "$f" in
        *.sh|"$file") continue ;;
    esac

    echo "Checking $f ..."
    result=$(diff --color=always "$file" "$f")
    if [ -n "$result" ]; then
        echo "========= Result ========"
        printf '%s\n' "$result"
        echo "========= End of result ======="
    fi
done

if [ -s "$tmpfile" ]; then
    rm "$tmpfile"
fi
