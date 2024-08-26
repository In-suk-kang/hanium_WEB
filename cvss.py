cvss_scores = {
    "int_undeflow": 7.5,
    "buffer_underwrite": 6.8,
    "buffer_overread": 7.1,
    "uncontrolled_format_string": 8.2,
    "memory_leak": 5.9,
    "buffer_underread": 6.5,
    "int_overflow": 7.3,
    2: 8.5, #heap_bof
    1: 9.0, #stack_bof
    0: 0.0 #secure
}


def get_cvss(vuln_name):
    score = cvss_scores.get(vuln_name, "Vulnerability not found")
    return score

