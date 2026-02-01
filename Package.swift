// swift-tools-version: 6.0
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "IlluminateAI_SDK",
	defaultLocalization: "en",
	platforms: [
		.iOS(.v15)
	],
    products: [
		.library(
			name: "IlluminateAI.xcframework",
			targets: ["IlluminateAI.xcframework"]),
		.library(
			name: "IlluminateAISupport.xcframework",
			targets: ["IlluminateAISupport.xcframework"]),
		.library(
			name: "elfSupport.xcframework",
			targets: ["elfSupport.xcframework"])
    ],
    targets: [
		.binaryTarget(
			name: "IlluminateAI.xcframework",
			path: "xcframeworks/IlluminateAI.xcframework"
		),
		.binaryTarget(
			name: "IlluminateAISupport.xcframework",
			path: "xcframeworks/IlluminateAISupport.xcframework"
		),
		.binaryTarget(
			name: "elfSupport.xcframework",
			path: "xcframeworks/elfSupport.xcframework"
		)
    ]
)
