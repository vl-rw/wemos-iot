import sys

import http.server
import socketserver



PORT = 1200



Handler = http.server.SimpleHTTPRequestHandler
print("serving at port", PORT)
with socketserver.TCPServer(("127.0.0.1", PORT), Handler) as httpd:
        httpd.serve_forever()
